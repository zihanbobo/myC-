   M S B A M L   `   `   `  ����[  WSystem.Windows.Forms, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089Y@clr-namespace:System.Windows.Forms;assembly=System.Windows.FormsSystem.Windows.Forms  5   	   F BSFMControls, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null>.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	   " 分布式停车场管理系统   UI.Video.RuleCfg_Form   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   Owf@clr-namespace:System.Windows.Forms;assembly=System.Windows.Forms     5   	   >src.clr-namespace:SFMControls;assembly=SFMControls     5   	   -   5          � Title$  规则配置��5   	   $	��627��6   $	��949��6#      WindowStyle#���   6/    � WindowStartupLocation$ CenterScreen=�6�    � 
ResizeMode$ NoResize=�6�   .��5      � .+�5   
   7  1System.Windows.Forms.Integration.WindowsFormsHost  -   5        $��wfhPicVideo��5      $
��Left=�6.   $	��491��6I   $	��Top=�6V   $	��616��6n   $��	30,45,0,0q�6z      Child. 5	      %   System.Windows.Forms.PictureBox  -   5        picBoxVideo��"   System.Windows.Forms.Control   Dock$
 Fill=�5	   2      SizeMode$ StretchImage=�6>      	BackColorU	 QSystem.Drawing, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a# 	 System.Drawing.ColorConverter$ Black 6V   5
      5      �� 5   
   $��规则名称��6   $
��Left=�6   $
��auto��6:   $��
655,45,0,0q�6H   $	��Top=�6\   $
��auto��6t   �� 5   
   -   5        $��txtRuleName��5      $
��Left=�6%   $��26��6@   $��
723,45,0,0q�6L    �� TextWrapping$
 Wrap=�6`   $	��Top=�6t   $	��123��6�   {�.  6�   �� 5   
   $��车牌宽度限制��6   $
��Left=�6!   $
��auto��6<   $��
655,94,0,0q�6J   $	��Top=�6^   $
��auto��6v   �� 5   
   -   5        $��txtMinWidth��5      $
��Left=�6%   $��26��6@   $��
741,94,0,0q�6L   $
 Wrap=�6`   $	��Top=�6t   $��50��6�   �� 5   
   $��-��6   $
��Left=�6   $
��auto��67   $��
795,94,0,0q�6E   $	��Top=�6Y   $
��auto��6q   �� 5   
   -   5        $��txtMaxWidth��5      $
��Left=�6%   $��26��6@   $��
815,94,0,0q�6L   $
 Wrap=�6`   $	��Top=�6t   $��50��6�   �� 5   
   $��(45-400)��6   $
��Left=�6#   $��26��6>   $��
874,94,0,0q�6J   $	��Top=�6^   $��64��6v   �� 5   
   $$��相同车牌触发间隔时间��6   $
��Left=�6%   $
��auto��6@   $��655,142,0,0q�6N   $	��Top=�6c   $
��auto��6{   �� 5   
   -   5        $��txtTimes��5      $
��Left=�6"   $��26��6=   $��790,142,0,0q�6I   $
 Wrap=�6^   $	��Top=�6r   $��75��6�   �� 5   
   $��(0-255)��6   $
��Left=�6"   $
��auto��6=   $��874,142,0,0q�6K   $	��Top=�6`   $
��auto��6x   �� 5   
   $��车辆通过方向��6   $
��Left=�6!   $
��auto��6<   $��655,188,0,0q�6J   $	��Top=�6_   $
��auto��6w   �� 5   
   -   5        $��cmbDir��5      $
��Left=�6!   $��26��6<   $��742,188,0,0q�6H   $	��Top=�6]   $	��132��6u   ��6�   Z� .@�5      �� .��6   双向6   �� 5      .��6   由上至下6!   �� 5      .��6   由下至上6!   5      �� 5   
   $��预设省份��6   $
��Left=�6   $
��auto��6:   $��655,235,0,0q�6H   $	��Top=�6]   $
��auto��6u   �� 5   
   -	   5        $��cmbSF��5      $
��Left=�6    $��26��6;   $��742,235,0,0q�6G   $	��Top=�6\   $	��132��6t   ��6�   Z�   SFMControls.ButtonSfm  5   
   -
   5        $��
btnAddRule��5      $��添加线圈��6*   $
��Left=�69   $��26��6T   $��677,290,0,0q�6`   $	��Top=�6u   $	��108��6�   6�     5   
   -   5        $��btnDeleRule��5      $��删除线圈��6+   $
��Left=�6:   $��26��6U   $��815,290,0,0q�6a   $	��Top=�6v   $	��108��6�   6�     5    
   -   5        $��btnTest��5       $��调试模式��6'   $
��Left=�66   $��26��6Q   $��815,340,0,0q�6]   $	��Top=�6r   $	��108��6�   6�     5!   
   -   5        $��btnSave��5!      $��保存设置��6'   $
��Left=�66   $��26��6Q   $��677,340,0,0q�6]   $	��Top=�6r   $	��108��6�   6�   �� 5"   
   -   5        $��chkDraw��5"      $	��是��6"   $
��Left=�6.   $��17��6I   $��816,511,0,0q�6U   $	��Top=�6j   $��54��6�   $y�	Collapsed=�6�   �� 5#   
   -   5        $��	chkEnable��5#      $	��是��6$   $
��Left=�60   $��20��6K   $��816,477,0,0q�6W   $	��Top=�6l   $��44��6�   $y�	Collapsed=�6�   �� 5$   
   $��是否检测��6   $
��Left=�6   $
��auto��6:   $��742,473,0,0q�6H   $	��Top=�6]   $
��auto��6u   $y�	Collapsed=�6�   �� 5%   
   $��是否绘制��6   $
��Left=�6   $
��auto��6:   $��742,506,0,0q�6H   $	��Top=�6]   $
��auto��6u   $y�	Collapsed=�6�     5&   
   -   5        $��wfhPic1��5&      $
��Left=�6*   $��79��6E   $	��Top=�6Q   $	��152��6i   $��713,385,0,0q�6u   $y�	Collapsed=�6�   . 5'        -   5        pictureBox1��$
 Fill=�5'   2   $ StretchImage=�6>   $ Black 6V   5(      5*      5+      