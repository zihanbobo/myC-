   M S B A M L   `   `   `  ����Y  U分布式停车场管理系统, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:UIUI  5   	   F BSFMControls, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null>.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	   >.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	       UI.frmPostpone   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   !codeclr-namespace:UI     5   	   FSFMControls.clr-namespace:SFMControls;assembly=SFMControls     5   	   >src.clr-namespace:SFMControls;assembly=SFMControls     5   	   -   5          � Title$  车辆延期��5   	   $	��375��6   $	��485��6#    � WindowStartupLocation$ CenterScreen=�6/    � 
ResizeMode$ NoResize=�6k      WindowStyle#���   6�   .��5      � .+�5	   
   �� $��车辆编号:��6   $
��Left=�6    $
��auto��6;   $��	16,10,0,0q�6I   $	��Top=�6\   $
��auto��6t   �� 5
   
   $��人员姓名:��6   $
��Left=�6    $
��auto��6;   $��
265,10,0,0q�6I   $	��Top=�6]   $
��auto��6u   �� 5   
   $��
车牌号:��6   $
��Left=�6   $
��auto��6:   $��	16,50,0,0q�6H   $	��Top=�6[   $
��auto��6s   �� 5   
   $��车辆类型:��6   $
��Left=�6    $
��auto��6;   $��	16,95,0,0q�6I   $	��Top=�6\   $
��auto��6t   �� 5   
   -   5        $��	lblCharge��5      $��收费规则:��6!   $
��Left=�61   $
��auto��6L   $��
16,141,0,0q�6Z   $	��Top=�6n   $
��auto��6�   �� 5   
   -   5        $��cmbRule��5      $
��Left=�6"   $
��auto��6=   $��
96,141,0,0q�6K   $	��Top=�6_   $	��103��6w   ��6�   Z� 6�   �� 5   
   $��人员编号:��6   $
��Left=�6    $
��auto��6;   $��
265,50,0,0q�6I   $	��Top=�6]   $
��auto��6u   �� 5   
   -   5        $
��lblY��5      $��余    额:��6   $
��Left=�6.   $
��auto��6I   $��
265,95,0,0q�6W   $	��Top=�6k   $
��auto��6�   �� 5   
   $��收取金额:��6   $
��Left=�6    $
��auto��6;   $��265,141,0,0q�6I   $	��Top=�6^   $
��auto��6v   �� 5   
   -   5        $��txtMoney��5      $��0��6"   $
��Left=�6+   $
��auto��6F   $��331,141,0,0q�6T    �� TextWrapping$
 Wrap=�6i   $	��Top=�6}   $	��112��6�   .��6   5      �� 5   
   $��有效止日:��6   $
��Left=�6    $
��auto��6;   $��265,185,0,0q�6I   $	��Top=�6^   $
��auto��6v   (  "System.Windows.Controls.DatePicker  5   
   -   5        $��
dtpEndTime��5      $
��Left=�6'   $��25��6B   $��331,186,0,0q�6N   $	��Top=�6c   $	��112��6{   �� 5   
   $��有效起日:��6   $
��Left=�6    $
��auto��6;   $��
16,186,0,0q�6I   $	��Top=�6]   $
��auto��6u     5   
   -   5        $��dtpStartTime��5      $
��Left=�6)   $��25��6D   $��
96,187,0,0q�6P   $	��Top=�6d   $	��103��6|   �� 5   
   $��备注:��6   $
��Left=�6   $
��auto��69   $��
16,223,0,0q�6G   $	��Top=�6[   $
��auto��6s   �� 5   
   -   5        $��
txtRemarks��5      $
��Left=�6$   $
��auto��6?   $��
96,223,0,0q�6M   $
 Wrap=�6a   $	��Top=�6u   $	��347��6�     SFMControls.ButtonSfm  5   
   -	   5        $��btnPrint��5       $��打印收费小票��60   $
��Left=�6A   $��26��6\   $��
51,278,0,0q�6h   $	��Top=�6|   $	��113��6�   {�.  6�     5   
   -
   5        $��btnPostpone��5       $��延  期��63   $
��Left=�6B   $��26��6]   $��206,278,0,0q�6i   $	��Top=�6~   $��80��6�   6�     5   
   -   5        $��btnExit��5       $��退  出��6/   $��26��6>   $��367,278,34,0q�6J   $	��Top=�6`   6x   �� 5   
   -   5        $��	lblCardNo��5      $��Label��6!   $
��Left=�61   $
��auto��6L   $��	96,10,0,0q�6Z   $	��Top=�6m   $	��103��6�   �� 5   
   -   5        $��lblCPH��5      $��Label��6   $
��Left=�6.   $
��auto��6I   $��	96,50,0,0q�6W   $	��Top=�6j   $	��103��6�   �� 5    
   -   5        $��lblCardType��5       $��Label��6#   $
��Left=�63   $
��auto��6N   $��	96,95,0,0q�6\   $	��Top=�6o   $	��103��6�   �� 5!   
   -   5        $��lblUserName��5!      $��Label��6#   $
��Left=�63   $
��auto��6N   $��
331,10,0,0q�6\   $	��Top=�6p   $	��112��6�   �� 5"   
   -   5        $��	lblUserNo��5"      $��Label��6!   $
��Left=�61   $
��auto��6L   $��
331,50,0,0q�6Z   $	��Top=�6n   $	��112��6�   �� 5#   
   -   5        $��
lblBalance��5#      $��Label��6"   $
��Left=�62   $
��auto��6M   $��
331,95,0,0q�6[   $	��Top=�6o   $	��112��6�   �� 5$   
   -   5        $��lblInfo��5$      $
��Left=�6   $
��auto��6:   $��144,250,0,0q�6H   $	��Top=�6]   $
��auto��6u   $y�Visible=�6�   �� 5%   
   -   5        $��rtbPrint��5%      $
��Left=�6&   $	��106��6A   $��450,260,-75,-37q�6N   $	��Top=�6g   $	��104��6   $y�Hidden=�6�   5'      5)      5*      