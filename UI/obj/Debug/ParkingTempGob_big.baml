   M S B A M L   `   `   `  ����Y  U分布式停车场管理系统, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:UIUI  5   	   F BSFMControls, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null>.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	   >.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	       UI.ParkingTempGob_big   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   !codeclr-namespace:UI     5   	   FSFMControls.clr-namespace:SFMControls;assembly=SFMControls     5   	   >src.clr-namespace:SFMControls;assembly=SFMControls     5   	   -   5          � Title$  临时车出场收费��5   	   $��Microsoft YaHei)�6   $��20(�66   $	��700��6[   $	��810��6h    � ShowInTaskbar .   � 
ResizeMode$ NoResize=�6�   $
��Left=�6�   $	��Top=�6�   .��5	      � -   5         �Name$ grdMain��5	      .+�5
   
   �� $��0q�6   .+�5      � -   5        $ 	gridPhoto��5      $��0q�6&   $	��Top=�61   $	��299��6I   .+�5      �� -   5         ��Name$ imgIn��5      $
��Left=�6'   $	��299��6B   $	��Top=�6O   $	��399��6g   $0��*pack://siteoforigin:,,,/Resources/car2.jpg��6s   $
��Fill=�6�   �� 5      -   5        $ imgOut��5      $
��Left=�6(   $	��299��6C   $	��Top=�6P   $	��399��6h   $0��*pack://siteoforigin:,,,/Resources/car2.jpg��6t   $��	403,0,0,0q�6�   $
��Fill=�6�   5      � 5      -   5        $ 
gridCharge��5      $��Center=�6'   $��0,10,0,0q�6D   $	��Top=�6V   $	��560��6n   $y�Visible=�6z   $	��360��6�   .+�5      �� $��车牌号码：��6   $
��Left=�6(   $��	10,10,0,0q�6C   $	��Top=�6V   �� 5      -   5         ��Name$ lblCPH��5      $��	粤B12345��6(   $
��Left=�6:   $��
130,10,0,0q�6U   $	��Top=�6i   �� 5      -   5        $ lblCardType��5      $��	无效卡��6-   $
��Left=�6;   $��
269,10,0,0q�6V   $	��Top=�6j   �� 5      $��入场时间：��6   $
��Left=�6(   $��	10,44,0,0q�6C   $	��Top=�6V   �� 5      -	   5        $ lblInDateTime��5      $��2015-01-01 10:01:01��6/   $
��Left=�6M   $��
130,44,0,0q�6h   $	��Top=�6|   �� 5      $��出场时间：��6   $
��Left=�6(   $��	10,73,0,0q�6C   $	��Top=�6V   �� 5      -
   5        $ lblOutDateTime��5      $��2015-01-01 10:01:01��60   $
��Left=�6N   $��
130,73,0,0q�6i   $	��Top=�6}   �� 5      $��停车时间：��6   $
��Left=�6(   $��
10,107,0,0q�6C   $	��Top=�6W   �� 5      -   5        $ lblTime��5      $��123天23小时45分��6)   $
��Left=�6?   $��130,107,0,0q�6Z   $	��Top=�6o   �� 5      $��停车费用：��6   $
��Left=�6(   $��
10,141,0,0q�6C   $	��Top=�6W   �� 5      -   5        $ lblSFJE��5      $��0��6)   $
��Left=�65   $��130,141,0,0q�6P   $	��Top=�6e   $	��118��6}   $��Center=�6�   
����  �6�   �� 5      $	��元��6   $
��Left=�6$   $��248,141,0,0q�6?   $	��Top=�6T   $��38��6l   �� 5      $��实收费用：��6   $
��Left=�6(   $��
10,175,0,0q�6C   $	��Top=�6W     SFMControls.NumericBox  5      -   5          Name$ txtSFJE��5   )   $
��Left=�6:   $��130,177,0,0q�6U    �� TextWrapping$
 Wrap=�6j   $	��Top=�6~   $	��117��6�   $��Center=�6�   
�������
���  �� �� 
IsReadOnly . 	   DecimalPlaces$	 2H�6�   �� 5      $	��元��6   $
��Left=�6$   $��248,175,0,0q�6?   $	��Top=�6T   $��38��6l     SFMControls.ButtonSfm  5      -   5        
  Name$
 btnPrint��5   (   $��打印小票��6:   $
��Left=�6I   $��286,157,0,0q�6d   $	��Top=�6y   $	��100��6�   6�     5       -   5        $
 btnFavorable��5    (   $��优惠��6>   $
��Left=�6K   $��286,177,0,0q�6f   $	��Top=�6{   $	��100��6�    J� RenderTransformOrigin$ 
0.47,1.594&�6�   $y�	Collapsed=�6�   �� 5!      $��打折地点：��6   $
��Left=�6(   $��
10,209,0,0q�6C   $	��Top=�6W   �� 5"      -   5         ��Name$ cmbJHDZ��5"      $
��Left=�6,   $��130,211,0,0q�6G   $	��Top=�6\   $	��256��6t   ��6�   Z� �� 5#      $��免费原因：��6   $
��Left=�6(   $��
10,243,0,0q�6C   $	��Top=�6W   �� 5$      -   5        $ cmbFree��5$      $
��Left=�6,   $��130,245,0,0q�6G   $	��Top=�6\   $	��256��6t   ��6�   Z� �� 5%      
���   �$��1q�6.   $
��Left=�6B   $��72��6]   $��	2,281,0,0q�6i   $	��Top=�6|   $	��384��6�   5&      �� 5'      $��电子支付：��6   $
��Left=�6(   $��
10,277,0,0q�6C   $	��Top=�6W   	� 5(      -   5         	�Name$ radWX��5(      $��微信��6-   $
��Left=�6:   $��130,282,0,0q�6U   $	��Top=�6j    d� 	IsChecked$
 TrueY�6�   	� 5)      -   5        $ radZFB��5)      $��	支付宝��6.   $
��Left=�6<   $��214,282,0,0q�6W   $	��Top=�6l   �� 5*      -   5         ��Name$ txtAuth_code��5*      $
��Left=�60   $��38��6K   $��
10,311,0,0q�6W   $
 Wrap=�6k   $�� ��6   $	��Top=�6�   $	��371��6�   6�   �� 5+      $��车辆类型��6   $
��Left=�6'   $��
401,10,0,0q�6B   $	��Top=�6V   �� 5,      -   5        $ cmbCardType��5,      $
��Left=�60   $��
401,44,0,0q�6K   $	��Top=�6_   $	��147��6w   ��6�   Z�   5-      -   5        $
 button3��5-   (   $��取消收费��69   $
��Left=�6H   $��
401,89,0,0q�6c   $	��Top=�6w   $	��147��6�   6�     5.      -   5        $
 btnVoice��5.   (   $��语音报价��6:   $
��Left=�6I   $��401,135,0,0q�6d   $	��Top=�6y   $	��147��6�   6�     5/      -   5        $
 	btnCutOff��5/   (   $��开闸放行��6;   $
��Left=�6J   $��401,181,0,0q�6e   $	��Top=�6z   $	��147��6�   6�     50      -   5        $
 	btnPapers��50   (   $��证件抓拍��6;   $
��Left=�6J   $��401,227,0,0q�6e   $	��Top=�6z   $	��147��6�   6�     51      -   5        $
 btnFree��51   (   $��免费放行��69   $
��Left=�6H   $��401,273,0,0q�6c   $	��Top=�6x   $	��147��6�   6�     52      -   5        $
 	btnGiveUp��52   (   $��放弃开闸��6;   $
��Left=�6J   $��401,319,0,0q�6e   $	��Top=�6z   $	��147��6�   6�   53      � 54      -   5        $ gridCPH��54      $��Center=�6$   $��0,10,0,0q�6A   $	��Top=�6S   $	��340��6k   $y�	Collapsed=�6x   .+�55      �� $��确认车牌��6   $
��Left=�6'   $��
149,17,0,0q�6B   $	��Top=�6V   �� 56      -   5        $ txtCPH0��56      $
��Left=�6+   $��36��6F   $��
244,17,0,0q�6R   $
 Wrap=�6f   $�� ��6z   $	��Top=�6�   $	��238��6�   6�     57      -   5        $
 button1��57   (   $��确定��69   $
��Left=�6F   $��
487,17,0,0q�6a   $	��Top=�6u   $��75��6�   6�   &   System.Windows.Controls.DataGrid  58      -   5          Name$ dgvFX��58      $
��Left=�6*   $��
149,62,0,0q�6E   $	��Top=�6Y   $	��210��6q   $	��194��6~      Columns 59      0  *System.Windows.Controls.DataGridTextColumn  5:      ,  &System.Windows.Controls.DataGridColumn   Header$ 发行车牌��6h   1  +System.Windows.Controls.DataGridBoundColumn   Binding 6-   �� *CPH+   ClipboardContentBinding 6E   Z� 6h   5<        5=      -    5        $ dgvCarIn��5=      $
��Left=�6-   $��
368,62,0,0q�6H   $	��Top=�6\   $	��210��6t   $	��194��6�    5>        5?      $ 场内车牌��6h    6-   �� *CPH+ 6E   Z� 6h   5A      �� 5B      $��操作提示:��6   $
��Left=�6(   $��
31,282,0,0q�6C   $	��Top=�6W   �� 5C      $
��Left=�6   $��131,287,0,0q�67   $
��Wrap=�6L   $����请在发行车牌栏或场内车牌栏选择正确入场记录,或者手动修改车牌结果.手动输入车牌可以模糊查询.��6`   $	��Top=�6�   $	��585��6�   5D      �� 5E      -!   5        $��rtbPrint��5E      $
��Left=�6*   $��69��6E   $��	727,0,0,0q�6Q   $��77��6d   $y�	Collapsed=�6o   5F      5H      5I      5J      