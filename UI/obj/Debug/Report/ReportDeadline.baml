   M S B A M L   `   `   `  ����Y  U分布式停车场管理系统, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:UIUI  5   	   F BSFMControls, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null>.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	   >.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	   O Kmscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e0891&clr-namespace:System;assembly=mscorlibSystem 5   	       UI.Report.ReportDeadline   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   !codeclr-namespace:UI     5   	   FSFMControls.clr-namespace:SFMControls;assembly=SFMControls     5   	   >src.clr-namespace:SFMControls;assembly=SFMControls     5   	   6sys&clr-namespace:System;assembly=mscorlib     5   	   -   5          � Title$  固定车期限查询��5   	   $	��459��6   $	��809��6&    � WindowStartupLocation$ CenterScreen=�62    � 
ResizeMode$ NoResize=�6n      WindowStyle#���   6�   .��5	      � .+�5
   
   &   System.Windows.Controls.DataGrid  -   5        $��dgvDeadline��5
      $
��Left=�6&   $	��220��6A   $��	10,10,0,0q�6N   $	��Top=�6a   $	��781��6y      CanUserAddRows .     AutoGenerateColumns .  ��6�   Z�    Columns 5      0  *System.Windows.Controls.DataGridTextColumn  5      ,  &System.Windows.Controls.DataGridColumn   Header$ 车牌号码��6%      Width5  /System.Windows.Controls.DataGridLengthConverter$ * 63      
IsReadOnly . 1  +System.Windows.Controls.DataGridBoundColumn	   Binding	 6=   �� *CPH+6i     5      $ 车辆编号��6%   $ * 63    . 	 6=   �� *CardNO+6l     5      $ 车辆类型��6%   $ * 63    . 	 6=   �� *
CardType+6n     5      $ 车场有效起日��6%   $ 2* 65    . 	 6@   �� *CarValidStartDate+
 �� StringFormat$
 
yyyy-MM-dd��6�     5      $ 车场有效止日��6%   $ 2* 65    . 	 6@   �� *CarValidEndDate+$
 
yyyy-MM-dd��6�     5      $ 剩余天数��6%   $ * 63    . 	 6=   �� *SurplusDays+6q     5      $ 人员姓名��6%   $ * 63    . 	 6=   �� *
UserName+6n     5      $ 部门名称��6%   $ * 63    . 	 6=   �� *
DeptName+6n     5      $ 手机号码��6%   $ 2* 63    . 	 6>   �� *	MobNumber+6p   5      �� 5   
   
���   �$��1q�6%   $
��Left=�69   $��85��6T   $��
10,246,0,0q�6`   $	��Top=�6t   $	��781��6�   ._�5      � .+�5      	� -   5        $��rbtSurplusDays��5      $��固定车剩余天数:��64   $
��Left=�6G   $
��auto��6b   $��	10,13,0,0q�6p   $	��Top=�6�   $
��auto��6�    d� 	IsChecked$
 TrueY�6�   	� 5      -   5        $��rbtTime��5      $��到期时间段:��6-   $
��Left=�6>   $
��auto��6Y   $��	10,49,0,0q�6g   $	��Top=�6z   $
��auto��6�   �� 5      -   5        $��txtSurplusDays��5      $��0��60   $
��Left=�69   $
��auto��6T   $��
118,10,0,0q�6b    �� TextWrapping$
 Wrap=�6v   $	��Top=�6�   $��89��6�   6�   �� 5      $	��到��6   $
��Left=�6$   $
��auto��6?   $��
212,46,0,0q�6M   $	��Top=�6a   $
��auto��6y   	� 5      -   5        $��rbtCarNo��5      $��车牌号码:��6.   $
��Left=�6>   $
��auto��6Y   $��
481,13,0,0q�6g   $	��Top=�6{   $
��auto��6�   	� 5      -   5        $��	rbtUserNo��5      $��人员编号:��6/   $
��Left=�6?   $
��auto��6Z   $��
481,52,0,0q�6h   $	��Top=�6|   $
��auto��6�   �� 5      -   5        $��txtCarNo��5      $
��Left=�6*   $
��auto��6E   $��
553,10,0,0q�6S   $
 Wrap=�6g   $	��Top=�6{   $	��125��6�    �� CharacterCasing$ Upper=�6�   �� 5       -	   5        $��	txtUserNo��5       $
��Left=�6+   $
��auto��6F   $��
553,49,0,0q�6T   $
 Wrap=�6h   $	��Top=�6|   $	��125��6�   6�   �� 5!      $��天内��6   $
��Left=�6%   $
��auto��6@   $��	212,8,0,0q�6N   $	��Top=�6a   $
��auto��6y   (  "System.Windows.Controls.DatePicker  5"      -
   5        $��dtStartTime��5"      $
��Left=�60   $
��auto��6K   $��	94,41,0,0q�6Y   $	��Top=�6l   $	��113��6�   
 �� Now   SelectedDate# Z 6�     5#      -   5        $��	dtEndTime��5#      $
��Left=�6.   $
��auto��6I   $��
239,41,0,0q�6W   $	��Top=�6k   $	��121��6�   # Z 6�   5%      5&      �� 5'   
   $
��Left=�6   $��33��60   $��182,352,0,0q�6<   $	��Top=�6Q   $	��401��6i    �� Orientation$ 
Horizontal=�6u   .+�5(        SFMControls.ButtonSfm  -   5        $��	btnSelect��5(   $   $��	查   询��65   $��33��6E   $	��Top=�6Q   $	��100��6i   $��0,0,50,0q�6u   6�     5)      -   5        $��	btnExport��5)   $   $��	导   出��65   $��33��6E   $	��Top=�6R   $	��100��6j   $��0,0,50,0q�6v      FormName$ 固定车期限查询��6�      ItemName$ 	CmdExport��6�     5*      -   5        $��btnExit��5*   $   $��	退   出��63   $��33��6C   $	��Top=�6P   $	��100��6h   6t   5+      �� 5,   
   $��查询数量:��6   $
��Left=�6    $
��auto��6;   $��661,356,0,0q�6I   $	��Top=�6^   $
��auto��6v   �� 5-   
   -   5        $��lblCount��5-      $��0��6    $
��Left=�6,   $
��auto��6G   $��727,355,0,0q�6U   $	��Top=�6j   $
��auto��6�   5/      50      