   M S B A M L   `   `   `  ����Y  U分布式停车场管理系统, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:UIUI  5   	   F BSFMControls, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null>.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	   >.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	       UI.ParkingOpen   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   !codeclr-namespace:UI     5   	   FSFMControls.clr-namespace:SFMControls;assembly=SFMControls     5   	   >src.clr-namespace:SFMControls;assembly=SFMControls     5   	   -   5          � Title$  电脑开闸��5   	   $	��222��6   $	��489��6#    � WindowStartupLocation$ CenterScreen=�6/    � 
ResizeMode$ NoResize=�6k      WindowStyle#���   6�   .��5      �  � RowDefinitions 5	   
   �� 5
      $��* �6   �� 5      $��* �6   �� 5      $��* �6    � ColumnDefinitions 5   
   �� 5      $
��0.5* �6   �� 5      $��* �6   �� 5      $��0.25* �6   �� 5      $
��0.5* �6   �� 5      $��* �6   .+�5   
   �� $��车辆编号:��6   $
��Left=�6    $
��auto��6;   $��	10,10,0,0q�6I   $	��Top=�6\   $
��auto��6t   �� 5   
   $��车牌号码:��6   $
��Left=�6    $
��auto��6;   $��	10,11,0,0q�6I   $��1��6\   $	��Top=�6i   $
��auto��6�   �� 5   
   -   5        $��	txtCardNO��5      $��1��6#   $
��Left=�63   $��28��6N   $��	10,10,0,0q�6Z    �� TextWrapping$
 Wrap=�6m   $	��Top=�6�   $	��128��6�   $��111111��6�   �� 5   
   $��车辆类型:��6   $��3��6    $
��Left=�60   $
��auto��6K   $��
10,10,0,12q�6Y   $��Center=�6m   $��64��6�   �� 5   
   -   5        $��cmbCardType��5      $��4��6&   $
��Left=�66   $
��auto��6Q   $��	14,12,0,0q�6_   $	��Top=�6r   $	��124��6�   ��6�   Z� �� 5   
   $��开闸事由:��6   $��3��6    $
��Left=�60   $
��auto��6K   $��
10,11,0,11q�6Y   $��1��6m   $��Center=�6z   $
��auto��6�   �� 5   
   -   5        $��cmbKZ��5      $��4��6    $
��Left=�60   $
��auto��6K   $��	14,11,0,0q�6Y   $��1��6l   $	��Top=�6y   $	��124��6�    �� 
IsEditable . .@�5      �� .��6   无6   �� 5      .��6   没有识别6!   �� 5      .��6   特殊车辆6!   5      �� 5    
   -   5        $��cmbCarNumber��5       $��1��6'   $
��Left=�67   $
��auto��6R   $��	10,15,0,0q�6`   $��1��6s   $	��Top=�6�   $	��128��6�    . .@�5!      �� .��6   京6   �� 5"      .��6   津6   �� 5#      .��6   冀6   �� 5$      .��6   晋6   �� 5%      .��6   蒙6   �� 5&      .��6   辽6   �� 5'      .��6   吉6   �� 5(      .��6   黑6   �� 5)      .��6   沪6   �� 5*      .��6   苏6   �� 5+      .��6   浙6   �� 5,      .��6   皖6   �� 5-      .��6   闽6   �� 5.      .��6   赣6   �� 5/      .��6   鲁6   �� 50      .��6   豫6   �� 51      .��6   鄂6   �� 52      .��6   湘6   �� 53      .��6   粤6   �� 54      .��6   桂6   �� 55      .��6   琼6   �� 56      .��6   渝6   �� 57      .��6   川6   �� 58      .��6   贵6   �� 59      .��6   云6   �� 5:      .��6   藏6   �� 5;      .��6   陕6   �� 5<      .��6   甘6   �� 5=      .��6   青6   �� 5>      .��6   宁6   �� 5?      .��6   新6   �� 5@      .��6   港6   �� 5A      .��6   澳6   �� 5B      .��6   台6   �� 5C      .��6   警6   �� 5D      .��6   军6   �� 5E      .��6   空6   �� 5F      .��6   海6   �� 5G      .��6   北6   �� 5H      .��6   沈6   �� 5I      .��6   兰6   �� 5J      .��6   济6   �� 5K      .��6   南6   �� 5L      .��6   广6   �� 5M      .��6   成6   5N        SFMControls.ButtonSfm  5O   
   -   5        $��btnOK��5O       $��确定��6-   $
��Left=�6:   $��30��6U   $��	28,10,0,0q�6a   $��2��6t   $	��Top=�6�   $��96��6�   $��1��6�   6�     5P   
   -   5        $��	btnCancel��5P       $��放弃��61   $��3��6>   $
��Left=�6N   $��30��6i   $��	26,10,0,0q�6u   $��2��6�   $	��Top=�6�   $��96��6�   $��2��6�   6�   5R      5S      