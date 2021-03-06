﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using SFMControls;
using ParkingCommunication.CameraSDK.ZNYKT5;
using System.Runtime.InteropServices;
using System.Threading;
using System.IO;

namespace UI.Video
{
    /// <summary>
    /// RuleCfg_Form.xaml 的交互逻辑
    /// </summary>
    public partial class RuleCfg_Form : SFMControls.WindowBase
    {
        private int lpr_handle_ = 0;
        private uint IMG_SIZE = 1920 * 1080;
        private byte[] pic_data_ = new byte[1920 * 1080];
        private IntPtr img_buf_ptr_;
        private GCHandle img_object_;

        private System.Timers.Timer draw_rule_timer_;
        public static Mutex mutex_rule_ = new Mutex();

        private const int LOOP_POINT_COUNT = 4;

        private System.Drawing.Graphics g_box_;
        private System.Drawing.Point[] loop_point_array_ = new System.Drawing.Point[LOOP_POINT_COUNT];
        private System.Drawing.Pen pen_loop_ = new System.Drawing.Pen(System.Drawing.Color.LightCoral, 2);

        private uint graph_width_ = 1280;
        private uint graph_heigh_ = 720;

        private const int BOUND_VALUE = 5;
        private const int SELE_BOUND_VALUE = 8;
        private const int CONTROL_BORDER = 2;

        private VzClientSDK.VZ_LPRC_VIRTUAL_LOOPS loops_ = new VzClientSDK.VZ_LPRC_VIRTUAL_LOOPS();

        private int active_pt_index_ = -1;

        private double zoom_x_rate = 0.0;
        private double zoom_y_rate = 0.0;

        private bool mouse_down_ = false;
        private System.Drawing.Point pt_mouse_down_ = new System.Drawing.Point();
        private System.Drawing.Point pt_prev_ = new System.Drawing.Point();
        private bool select_loop_ = false;

        public RuleCfg_Form()
        {
            InitializeComponent();
        }

        public RuleCfg_Form(int handle)
        {
            InitializeComponent();
            lpr_handle_ = handle;
        }

        private void WindowBase_Loaded(object sender, RoutedEventArgs e)
        {
            // 开启获取实时解码数据
            if (lpr_handle_ > 0)
            {
                VzClientSDK.VzLPRClient_StartRealPlayDecData(lpr_handle_);
                VzClientSDK.VZ_LPRC_PROVINCE_INFO PROVINCE = new VzClientSDK.VZ_LPRC_PROVINCE_INFO();
                VzClientSDK.VzLPRClient_GetSupportedProvinces(lpr_handle_, ref PROVINCE);

                string sProvinces = new string(PROVINCE.strProvinces).Trim('\0');
                cmbSF.Items.Clear();
                cmbSF.Items.Add("无");
                for (int i = 0; i < sProvinces.Length; i++)
                {
                    cmbSF.Items.Add(sProvinces.Substring(i, 1));
                }
                if (cmbSF.Items.Count > PROVINCE.nCurrIndex)
                {
                    cmbSF.SelectedIndex = PROVINCE.nCurrIndex + 1;
                }
            }

            img_object_ = GCHandle.Alloc(pic_data_, GCHandleType.Pinned);
            img_buf_ptr_ = img_object_.AddrOfPinnedObject();

            draw_rule_timer_ = new System.Timers.Timer(80);
            draw_rule_timer_.Elapsed += drawTimer_Elapsed;
            draw_rule_timer_.AutoReset = true;
            draw_rule_timer_.Enabled = true;

            g_box_ = picBoxVideo.CreateGraphics();

            LoadRuleParam();
        }

        private void LoadRuleParam()
        {
            if (lpr_handle_ > 0)
            {
                // 加载虚拟线圈的规则
                int ret = VzClientSDK.VzLPRClient_GetVirtualLoop(lpr_handle_, ref loops_);

                if (loops_.uNumVirtualLoop > 0)
                {
                    LoadLoopParam();

                    uint x = 0, y = 0;
                    for (int i = 0; i < LOOP_POINT_COUNT; i++)
                    {
                        x = loops_.struLoop[0].struVertex[i].X_1000 * graph_width_ / 1000;
                        y = loops_.struLoop[0].struVertex[i].Y_1000 * graph_heigh_ / 1000;

                        loop_point_array_[i] = new System.Drawing.Point((int)x, (int)y);
                    }

                    zoom_x_rate = (double)picBoxVideo.Width / (double)graph_width_;
                    zoom_y_rate = (double)picBoxVideo.Height / (double)graph_heigh_;
                }
                else
                {
                    EnableLoopParamCtrl(false);
                }
            }
        }

        private void drawTimer_Elapsed(object sender, System.Timers.ElapsedEventArgs e)
        {
            mutex_rule_.WaitOne();

            int nBufSize = VzClientSDK.VzLPRClient_GetJpegStreamFromRealPlayDec(lpr_handle_, img_buf_ptr_, IMG_SIZE, 100);
            if (nBufSize > 0)
            {
                // 显示图像到界面
                MemoryStream ms = new MemoryStream(pic_data_);
                System.Drawing.Bitmap bitmap = new System.Drawing.Bitmap(ms);

                System.Drawing.Graphics g = System.Drawing.Graphics.FromImage(bitmap);

                if (loops_.uNumVirtualLoop == 1)
                {
                    g.DrawPolygon(pen_loop_, loop_point_array_);

                    if (graph_width_ != bitmap.Width || graph_heigh_ != bitmap.Height)
                    {
                        graph_width_ = (uint)bitmap.Width;
                        graph_heigh_ = (uint)bitmap.Height;

                        zoom_x_rate = (double)picBoxVideo.Width / (double)graph_width_;
                        zoom_y_rate = (double)picBoxVideo.Height / (double)graph_heigh_;

                        ReloadLoop();
                    }

                    for (int i = 0; i < LOOP_POINT_COUNT; i++)
                    {
                        if (i == active_pt_index_)
                        {
                            g.DrawRectangle(System.Drawing.Pens.LightGreen, loop_point_array_[i].X - SELE_BOUND_VALUE, loop_point_array_[i].Y - SELE_BOUND_VALUE, SELE_BOUND_VALUE * 2, SELE_BOUND_VALUE * 2);
                        }
                        else
                        {
                            g.DrawRectangle(System.Drawing.Pens.LightYellow, loop_point_array_[i].X - BOUND_VALUE, loop_point_array_[i].Y - BOUND_VALUE, BOUND_VALUE * 2, BOUND_VALUE * 2);
                        }
                    }
                }
                System.Drawing.Rectangle rc_dest = new System.Drawing.Rectangle(0, 0, picBoxVideo.Width, picBoxVideo.Height);
                System.Drawing.Rectangle rc_src = new System.Drawing.Rectangle(0, 0, bitmap.Width, bitmap.Height);
                g_box_.DrawImage(bitmap, rc_dest, rc_src, System.Drawing.GraphicsUnit.Pixel);
            }

            mutex_rule_.ReleaseMutex();
        }

        private void ReloadLoop()
        {
            for (int i = 0; i < LOOP_POINT_COUNT; i++)
            {
                loop_point_array_[i].X = (int)(loops_.struLoop[0].struVertex[i].X_1000 * graph_width_ / 1000);
                loop_point_array_[i].Y = (int)(loops_.struLoop[0].struVertex[i].Y_1000 * graph_heigh_ / 1000);
            }
        }

        private void LoadLoopParam()
        {
            string rule_name = loops_.struLoop[0].strName;
            txtRuleName.Text = rule_name;

            uint time_gap = loops_.struLoop[0].uTriggerTimeGap;
            txtTimes.Text = time_gap.ToString();

            if (loops_.struLoop[0].byDraw == 1)
            {
                chkDraw.IsChecked = true;
            }

            if (loops_.struLoop[0].byEnable == 1)
            {
                chkEnable.IsChecked = true;
            }

            uint min_lp_width = loops_.struLoop[0].uMinLPWidth;
            uint max_lp_width = loops_.struLoop[0].uMaxLPWidth;

            txtMinWidth.Text = min_lp_width.ToString();
            txtMaxWidth.Text = max_lp_width.ToString();

            uint cross_dir = loops_.struLoop[0].eCrossDir;
            if (cross_dir >= 0 && cross_dir < 3)
            {
                cmbDir.SelectedIndex = (int)cross_dir;
            }
            else
            {
                cmbDir.SelectedIndex = 0;
            }
        }

        private void EnableLoopParamCtrl(bool enable)
        {
            txtMinWidth.IsEnabled = enable;
            txtMaxWidth.IsEnabled = enable;
            txtTimes.IsEnabled = enable;
            cmbDir.IsEnabled = enable;
            chkDraw.IsEnabled = enable;
            chkEnable.IsEnabled = enable;
        }

        private void WindowBase_Closed(object sender, EventArgs e)
        {
            draw_rule_timer_.Enabled = false;
            draw_rule_timer_.Stop();

            VzClientSDK.VzLPRClient_StopRealPlayDecData(lpr_handle_);

            if (img_object_.IsAllocated)
            {
                img_object_.Free();
            }
        }

        private void btnAddRule_Click(object sender, RoutedEventArgs e)
        {
            if (loops_.uNumVirtualLoop >= 1)
            {
                MessageBox.Show("只允许配置一个虚拟线圈！");
                return;
            }

            int RULE_GRAPH_BORDER = 100;

            int nWidth = (int)graph_width_;
            int nHeight = (int)graph_heigh_;

            int nMaxWidth = nWidth - RULE_GRAPH_BORDER;
            int nMaxHeight = nHeight - RULE_GRAPH_BORDER;

            System.Drawing.Point pt1 = new System.Drawing.Point(RULE_GRAPH_BORDER, RULE_GRAPH_BORDER + nMaxHeight / 2);
            System.Drawing.Point pt2 = new System.Drawing.Point(nWidth - RULE_GRAPH_BORDER, RULE_GRAPH_BORDER + nMaxHeight / 2);
            System.Drawing.Point pt3 = new System.Drawing.Point(nWidth - RULE_GRAPH_BORDER, nHeight - RULE_GRAPH_BORDER);
            System.Drawing.Point pt4 = new System.Drawing.Point(RULE_GRAPH_BORDER, nMaxHeight);

            loop_point_array_[0] = pt1;
            loop_point_array_[1] = pt2;
            loop_point_array_[2] = pt3;
            loop_point_array_[3] = pt4;

            loops_.uNumVirtualLoop = 1;

            loops_.struLoop[0].strName = "电子线圈";
            loops_.struLoop[0].eCrossDir = 0;
            loops_.struLoop[0].uTriggerTimeGap = 10;
            loops_.struLoop[0].byDraw = 1;
            loops_.struLoop[0].byEnable = 1;
            loops_.struLoop[0].uMinLPWidth = 45;
            loops_.struLoop[0].uMaxLPWidth = 400;
            loops_.uNumVirtualLoop = 1;

            LoadLoopParam();

            EnableLoopParamCtrl(true);
        }

        private void btnDeleRule_Click(object sender, RoutedEventArgs e)
        {
            loops_.uNumVirtualLoop = 0;

            for (int i = 0; i < LOOP_POINT_COUNT; i++)
            {
                loop_point_array_[i].X = 0;
                loop_point_array_[i].Y = 0;
            }

            EnableLoopParamCtrl(false);
        }

        private void btnTest_Click(object sender, RoutedEventArgs e)
        {
            if (btnTest.Content.ToString() == "关闭调试")
            {
                btnTest.Content = "调试模式";
                wfhPic1.Visibility = Visibility.Collapsed;
            }
            else
            {
                wfhPic1.Visibility = Visibility.Visible;
                wfhPic1.Width = wfhPicVideo.Width;
                wfhPic1.Height = wfhPicVideo.Height;
                wfhPic1.Margin = wfhPicVideo.Margin;
                pictureBox1.Image = Properties.Resources.Debugtemplate;
                btnTest.Content = "关闭调试";
            }
        }

        private void btnSave_Click(object sender, RoutedEventArgs e)
        {
            if (lpr_handle_ > 0)
            {
                if (loops_.uNumVirtualLoop == 1)
                {
                    for (int i = 0; i < LOOP_POINT_COUNT; i++)
                    {
                        loops_.struLoop[0].struVertex[i].X_1000 = (uint)(loop_point_array_[i].X * 1000 / graph_width_);
                        loops_.struLoop[0].struVertex[i].Y_1000 = (uint)(loop_point_array_[i].Y * 1000 / graph_heigh_);
                    }

                    loops_.struLoop[0].uMinLPWidth = uint.Parse(txtMinWidth.Text);
                    loops_.struLoop[0].uMaxLPWidth = uint.Parse(txtMaxWidth.Text);
                    loops_.struLoop[0].uTriggerTimeGap = uint.Parse(txtTimes.Text);
                    loops_.struLoop[0].eCrossDir = (uint)(cmbDir.SelectedIndex);
                    loops_.struLoop[0].byDraw = (chkDraw.IsChecked.Value ? (byte)1 : (byte)0);
                    loops_.struLoop[0].byEnable = (chkEnable.IsChecked.Value ? (byte)1 : (byte)0);
                }
                else
                {
                    // 清空数据
                    for (int i = 0; i < LOOP_POINT_COUNT; i++)
                    {
                        loops_.struLoop[0].struVertex[i].X_1000 = 0;
                        loops_.struLoop[0].struVertex[i].Y_1000 = 0;
                    }
                    loops_.struLoop[0].strName = "";
                    loops_.struLoop[0].uMinLPWidth = 0;
                    loops_.struLoop[0].uMaxLPWidth = 0;
                    loops_.struLoop[0].uTriggerTimeGap = 0;
                    loops_.struLoop[0].eCrossDir = 0;
                    loops_.struLoop[0].byDraw = 0;
                    loops_.struLoop[0].byEnable = 0;
                }
                VzClientSDK.VzLPRClient_PresetProvinceIndex(lpr_handle_, cmbSF.SelectedIndex - 1);
                int ret = VzClientSDK.VzLPRClient_SetVirtualLoop(lpr_handle_, ref loops_);

                if (ret == 0)
                {
                    MessageBox.Show("保存线圈参数成功！");
                }
                else
                {
                    MessageBox.Show("保存线圈参数失败！");
                }
            }
        }

        private System.Drawing.Point PointToImgPoint(System.Drawing.Point pt)
        {
            System.Drawing.Point pt_img = new System.Drawing.Point();

            pt_img.X = GetImgX(pt.X);
            pt_img.Y = GetImgY(pt.Y);

            return pt_img;
        }

        private int GetImgX(int x)
        {
            int img_x = x;
            if (zoom_x_rate > 0.01)
            {
                img_x = (int)(x / zoom_x_rate);
            }

            return img_x;
        }

        private int GetImgY(int y)
        {
            int img_y = y;

            if (zoom_y_rate > 0.01)
            {
                img_y = (int)(y / zoom_y_rate);
            }

            return img_y;
        }

        bool PointIsInPolygen(System.Drawing.Point pt)
        {
            System.Drawing.Point pt0, pt1;
            int dist = 0;
            int counter = 0;

            bool result = false;

            for (int i = 0; i < LOOP_POINT_COUNT - 1; i++)
            {
                pt0 = loop_point_array_[i];
                pt1 = loop_point_array_[i + 1];

                if ((pt0.Y <= pt.Y && pt1.Y <= pt.Y) ||
                        (pt0.Y > pt.Y && pt1.Y > pt.Y) ||
                        (pt0.X < pt.X && pt1.X < pt.X))
                {
                    if (pt.Y == pt1.Y && (pt.X == pt1.X || (pt.Y == pt0.Y &&
                        ((pt0.X <= pt.X && pt.X <= pt1.X) || (pt1.X <= pt.X && pt.X <= pt0.X)))))
                        return true;
                    continue;
                }


                dist = (pt.Y - pt0.Y) * (pt1.X - pt0.X) - (pt.X - pt0.X) * (pt1.Y - pt0.Y);
                if (dist == 0)
                    return true;
                if (pt1.Y < pt0.Y)
                    dist = -dist;

                if (dist > 0)
                {
                    counter++;
                }
                // counter += dist > 0;
            }

            result = (counter % 2) == 0 ? false : true;
            return result;
        }

        private System.Drawing.Point GetInBoundPoint(System.Drawing.Point pt)
        {
            System.Drawing.Point ptResult = pt;

            if (ptResult.X < 0)
            {
                ptResult.X = 0;
            }

            if (ptResult.X > ((int)graph_width_ - CONTROL_BORDER))
            {
                ptResult.X = (int)graph_width_ - CONTROL_BORDER;
            }

            if (ptResult.Y < 0)
            {
                ptResult.Y = 0;
            }

            if (ptResult.Y > ((int)graph_heigh_ - CONTROL_BORDER))
            {
                ptResult.Y = (int)graph_heigh_ - CONTROL_BORDER;
            }

            return ptResult;
        }

        private bool GetEditIsCross(int nPtIndex, System.Drawing.Point ptMouse)
        {
            int nMaxIndex = LOOP_POINT_COUNT - 1;

            bool bCross = false;
            bool bCross1, bCross2;

            System.Drawing.Point ptEdge1Start, ptEdge1End;
            System.Drawing.Point ptEdge2Start, ptEdge2End;

            System.Drawing.Point ptStart, ptEnd;

            // 移动起点
            if (nPtIndex == 0)
            {
                ptStart = loop_point_array_[1];
                ptEnd = ptStart;

                // 第一条边
                ptEdge1Start = ptMouse;
                ptEdge1End = loop_point_array_[1];

                for (int i = 2; i < LOOP_POINT_COUNT; i++)
                {
                    ptEnd = loop_point_array_[i];
                    bCross = GetLineIsCross(ptEdge1Start, ptEdge1End, ptStart, ptEnd);

                    if (bCross)
                    {
                        break;
                    }

                    ptStart = ptEnd;
                }
            } // 移动终点
            else if (nPtIndex == nMaxIndex)
            {
                ptStart = loop_point_array_[0];
                ptEnd = ptStart;

                // 第一条边
                ptEdge1Start = loop_point_array_[nMaxIndex - 1];
                ptEdge1End = ptMouse;

                for (int i = 1; i < nMaxIndex; i++)
                {
                    ptEnd = loop_point_array_[i];
                    bCross = GetLineIsCross(ptEdge1Start, ptEdge1End, ptStart, ptEnd);

                    if (bCross)
                    {
                        break;
                    }

                    ptStart = ptEnd;
                }
            }
            else
            {
                ptStart = loop_point_array_[0];
                ptEnd = ptStart;

                // 第一条边
                ptEdge1Start = loop_point_array_[nPtIndex - 1];
                ptEdge1End = ptMouse;

                // 第二条边
                ptEdge2Start = ptMouse;
                ptEdge2End = loop_point_array_[nPtIndex + 1];

                for (int i = 1; i < LOOP_POINT_COUNT; i++)
                {
                    ptEnd = loop_point_array_[i];

                    if ((i == nPtIndex) || (i == (nPtIndex + 1)))
                    {
                        ptStart = ptEnd;
                        continue;
                    }

                    bCross1 = GetLineIsCross(ptEdge1Start, ptEdge1End, ptStart, ptEnd);
                    bCross2 = GetLineIsCross(ptEdge2Start, ptEdge2End, ptStart, ptEnd);

                    if (bCross1 || bCross2)
                    {
                        bCross = true;
                        break;
                    }

                    ptStart = ptEnd;
                }
            }

            return bCross;
        }

        private void MoveBoundLimit(ref int nDisX, ref int nDisY)
        {
            int nCurX = 0;
            int nCurY = 0;

            for (int i = 0; i < LOOP_POINT_COUNT; i++)
            {
                nCurX = loop_point_array_[i].X + nDisX;
                nCurY = loop_point_array_[i].Y + nDisY;

                if (nCurX > ((int)graph_width_ - CONTROL_BORDER))
                {
                    nCurX = ((int)graph_width_ - CONTROL_BORDER);
                }
                else if (nCurX < 0)
                {
                    nCurX = 0;
                }
                nDisX = nCurX - loop_point_array_[i].X;

                if (nCurY > ((int)graph_heigh_ - CONTROL_BORDER))
                {
                    nCurY = ((int)graph_heigh_ - CONTROL_BORDER);
                }
                else if (nCurY < 0)
                {
                    nCurY = 0;
                }
                nDisY = nCurY - loop_point_array_[i].Y;
            }
        }

        private bool GetLineIsCross(System.Drawing.Point ptMa, System.Drawing.Point ptMb, System.Drawing.Point ptNa, System.Drawing.Point ptNb)
        {
            double dbV1, dbV2, dbV3, dbV4;

            dbV1 = (ptMb.X - ptMa.X) * (ptNb.Y - ptMa.Y) - (ptMb.Y - ptMa.Y) * (ptNb.X - ptMa.X);
            dbV2 = (ptMb.X - ptMa.X) * (ptNa.Y - ptMa.Y) - (ptMb.Y - ptMa.Y) * (ptNa.X - ptMa.X);

            double dbResult1 = dbV1 * dbV2;
            if (dbResult1 >= 0)
            {
                return false;
            }

            dbV3 = (ptNb.X - ptNa.X) * (ptMb.Y - ptNa.Y) - (ptNb.Y - ptNa.Y) * (ptMb.X - ptNa.X);
            dbV4 = (ptNb.X - ptNa.X) * (ptMa.Y - ptNa.Y) - (ptNb.Y - ptNa.Y) * (ptMa.X - ptNa.X);

            double dbResult2 = dbV3 * dbV4;
            if (dbResult2 >= 0)
            {
                return false;
            }

            return true;
        }

        private void MoveAllPoints(int dis_x, int dis_y)
        {
            for (int i = 0; i < LOOP_POINT_COUNT; i++)
            {
                loop_point_array_[i].X += dis_x;
                loop_point_array_[i].Y += dis_y;
            }
        }

        private int GetPointIndex(System.Drawing.Point pt, int max_dist)
        {
            int index = -1;
            int dist = 0;
            for (int i = 0; i < LOOP_POINT_COUNT; i++)
            {
                dist = Point2PointDist(pt, loop_point_array_[i]);
                if (dist <= max_dist)
                {
                    max_dist = dist;
                    index = i;
                }
            }
            return index;
        }

      
        private int Point2PointDist(System.Drawing.Point pt_start, System.Drawing.Point pt_end)
        {
            double dbDist = (pt_start.X - pt_end.X) * (pt_start.X - pt_end.X) + (pt_start.Y - pt_end.Y) * (pt_start.Y - pt_end.Y);
            int nDist = (int)Math.Sqrt(dbDist);
            return nDist;
        }

        private void picBoxVideo_MouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            pt_mouse_down_.X = e.X;
            pt_mouse_down_.Y = e.Y;

            System.Drawing.Point pt_img = PointToImgPoint(pt_mouse_down_);

            select_loop_ = PointIsInPolygen(pt_img);
            if (select_loop_)
            {
                pt_prev_ = pt_img;
            }

            mouse_down_ = true;
        }

        private void picBoxVideo_MouseMove(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            System.Drawing.Point pt_mouse = new System.Drawing.Point(e.X, e.Y);
            System.Drawing.Point pt_img = PointToImgPoint(pt_mouse);

            int dis_x = 0, dis_y = 0;

            if (mouse_down_)
            {
                if (active_pt_index_ >= 0 && active_pt_index_ < LOOP_POINT_COUNT)
                {
                    System.Drawing.Point ptNow = GetInBoundPoint(pt_img);
                    if (!GetEditIsCross(active_pt_index_, ptNow))
                    {
                        // 移动点
                        loop_point_array_[active_pt_index_] = ptNow;
                    }
                }
                else
                {
                    // 移动整个图形
                    if (select_loop_)
                    {
                        // 获取当前位置与之前位置的坐标差
                        dis_x = pt_img.X - pt_prev_.X;
                        dis_y = pt_img.Y - pt_prev_.Y;

                        // 如果图形上所有的点没有超过图形范围，则移动图形
                        MoveBoundLimit(ref dis_x, ref dis_y);

                        if (dis_x != 0 || dis_y != 0)
                        {
                            MoveAllPoints(dis_x, dis_y);

                            // 保存之前的坐标
                            pt_prev_.X += dis_x;
                            pt_prev_.Y += dis_y;
                        }
                    }
                }
            }
            else
            {
                active_pt_index_ = GetPointIndex(pt_img, 10);

                PointIsInPolygen(pt_img);
            }
        }

        private void picBoxVideo_MouseUp(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            mouse_down_ = false;
        }
    }
}
