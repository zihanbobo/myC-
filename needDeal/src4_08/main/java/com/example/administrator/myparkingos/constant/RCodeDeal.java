package com.example.administrator.myparkingos.constant;

import com.example.administrator.myparkingos.util.L;

/**
 * Created by Administrator on 2017-03-27.
 */
public class RCodeDeal
{

    /**
     * 处理服务器返回的rcode值
     * <p/>
     * 40000.已经失效
     * 40001.未知异常
     * 40002.输入参数缺失
     * 40003.token已过期
     * 40004.用户重复登录
     * 40005.工作站重复
     * 40006.无权限             ==>>直接结束
     * <p/>
     * 40007.固定车过期禁止入出场
     * 40008.车道未授权
     * 400010.多车多位满位禁止入场
     * 40012.储值车余额不足     ==>>>发送语音 -->>结束 1【主要针对的是固定车】
     * <p/>
     * 40013.黑名单禁止入出场
     * 40015.月租车位已满
     * 40016.临时车位已满
     * 40017.储值车位已满
     * 40018.所有车位已满
     * 40020.全字母车牌禁止入出场
     * 40021.全字符相同车牌禁止入出场
     * 40026.临时车禁止入小车场  ==>>>发送语音 -->>结束 2 和结束1不同之处是发送语音的内容不同【主要针对的是非固定车】
     * <p/>
     * -3.重复入场
     * -2.月租车过期按临时车收费
     * -1.多车位多车已满按临时车收费
     * 200.正常入场             ==>>发送开闸指令->>>发语音 -->>结束
     * <p/>
     * 40027.确认开闸模式
     * 40030.月租车位已满确认开闸
     * 40031.临时车位已满确认开闸
     * 40032.储值车位已满确认开闸
     * 40033.所有车位已满确认开闸 ==>>是否放行 是，则发送开闸指令->>>发语音 -->>结束；否，发送语音 -->>结束
     * <p/>
     * 返回值：
     * -1，直接结束
     * 0，可以入场，且正常
     * 1，发送语音提示信息，后结束，针对于固定月租车
     * 2，发送语音提示信息，后结束，针对于非固定车
     * 3，发送开闸指令,发语音，结束
     * 4，判断是否放行，发送开闸指令，结束
     */
//    public static int detectionCarInRcode(int inRcode)
//    {
//        int returnValue = -1;
//        switch (inRcode)
//        {
//            case 40000:
//            case 40001:
//            case 40002:
//            case 40003:
//            case 40004:
//            case 40005:
//            case 40006:
//                returnValue = -1;
//                break;
//            case 200:
//                returnValue = 0;
//                break;
//            case 40007:
//            case 40008:
//            case 40010:
//            case 40012:
//                returnValue = 1;
//                break;
//            case 40013:
//            case 40015:
//            case 40016:
//            case 40017:
//            case 40018:
//            case 40020:
//            case 40021:
//            case 40026:
//                returnValue = 2;
//                break;
//            case -3:
//            case -2:
//            case -1:
//                returnValue = 3;
//                break;
//            case 40027:
//            case 40030:
//            case 40031:
//            case 40032:
//            case 40033:
//                returnValue = 4;
//                break;
//            default:
//            {
//                break;
//            }
//        }
//        return returnValue;
//    }

    /**
     * 检测车辆出场的Rcode的值
     * @param inRcode
     * @return
     */

    /**
     * 返回值
     * 40000.已经失效
     * 40001.未知异常
     * 40002.输入参数缺失
     * 40003.token已过期
     * 40004.用户重复登录
     * 40005.工作站重复
     * 40006.无权限
     * <p/>
     * 40007.固定车过期禁止出场
     * 40008.登记车牌无此车场权限
     * 40012.储值车余额不足禁止出场
     * 40013.黑名单车辆
     * 40014.禁止开闸模式
     * 40020.全字母车牌不处理
     * 40021.全字符相同车牌不处理
     * <p/>
     * 200 自动开闸
     * <p/>
     * 40027 无入场开闸放行
     * <p/>
     * 返回值：
     * -1， 直接结束
     * 0， 开闸之后，发语音
     * 1，自动开闸，然后再做下一步的判断
     * 2，没有入场记录开闸放行
     */
//    public static int detectionCarOutRcode(int inRcode)
//    {
//        RCode rCode = RCode.valueOf(inRcode);
//        switch (rCode)
//        {
//            case RepeatAdmission:
//                break;
//            case MthBeOverdueToTmpCharge:
//                break;
//            case MthFullToTmpCharge:
//                break;
//            default:
//            {
//                break;
//            }
//        }
//        return retureValue;
//    }


    /** 04_07
     * 入场带剩余车位播报语音
     * @param strIP ip地址
     * @param iJiHao 机号
     * @param strCPH 车牌号码
     * @param iSurplus 剩余车位（整数）
     * @param CYkDay 固定车剩余天数（当不为固定车时直接传0）
     * @param CCzkMoney 储值车余额（当不为储值车时直接传0）
     * @param iIDNoticeDay 车场设置中的播报天数
     * @param strCardCW  车场车位
     * @param bCtrlShowCW 是否播报车场车位
     * @param CarTypeenum 车场卡类枚举
     * @return
     */

}