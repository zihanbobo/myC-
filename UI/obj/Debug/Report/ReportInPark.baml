   M S B A M L   `   `   `  ����F  BSFMControls, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null>.clr-namespace:SFMControls;assembly=SFMControlsSFMControls  5   	   >.clr-namespace:SFMControls;assembly=SFMControlsSFMControls  5   	   Y U分布式停车场管理系统, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:UIUI 5   	   [ WSystem.Windows.Forms, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089Y@clr-namespace:System.Windows.Forms;assembly=System.Windows.FormsSystem.Windows.Forms 5   	   O Kmscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e0891&clr-namespace:System;assembly=mscorlibSystem 5   	   clr-namespace:UIUI 5	   	   1&clr-namespace:System;assembly=mscorlibSystem 5
   	   %clr-namespace:UI.Report	UI.Report 5   	      UI.Report.ReportInPark   5      >SFMControls.clr-namespace:SFMControls;assembly=SFMControls  5   	   6src.clr-namespace:SFMControls;assembly=SFMControls  5   	   codeclr-namespace:UI  5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      5   	   R	 NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml 	    5   	   Owf@clr-namespace:System.Windows.Forms;assembly=System.Windows.Forms 	    5   	   6sys&clr-namespace:System;assembly=mscorlib 	    5   	    cvtclr-namespace:UI 	    5	   	   ;assembly&clr-namespace:System;assembly=mscorlib 	    5
   	   )localclr-namespace:UI.Report 	    5   	   -   5          � Title$  场内车辆查询��5   	   $	��629��6   $	��980��6%    � WindowStartupLocation$ CenterScreen=�61    � 
ResizeMode$ NoResize=�6�      WindowStyle#���   6�    � 	Resources 5        UI.OperatorConverter 	 cvtOT  UI.DateConverter  cvtDate��%:   &	       &	        5   
   6      5   
   6   5      .��5      � .+�5   
   �� -   5        $��tbSelect��5      ��6%   Z� .@�5      �� $��查询条件��6   ��6$   Z� .��5      � .+�5      �� 
���   �$��1q�61   $��Center=�6E   $	��390��6b   $��Center=�6p   $	��676��6�   ._�5      � .+�5      �� $��时间范围��6$   $
��Left=�63   $
��auto��6N   $��
116,10,0,0q�6\   $	��Top=�6p   $
��auto��6�   (  "System.Windows.Controls.DatePicker  5      -   5        $��dtStartTime��5   )   $
��Left=�6<   $��30��6W   $��
199,10,0,0q�6c   $	��Top=�6w   $	��130��6�   
 �� Now   SelectedDate# Z 6�   �� 5      $	��到��6$   $
��Left=�60   $
��auto��6K   $��	356,9,0,0q�6Y   $	��Top=�6l   $
��auto��6�     5      -   5        $��	dtEndTime��5   )   $
��Left=�6:   $��30��6U   $��
383,10,0,0q�6a   $	��Top=�6u   $	��149��6�   # Z 6�   &   System.Windows.Controls.DataGrid  5      -   5        $��dgvQuery��5   '   $
��Left=�6O   $	��230��6j   $��	10,41,0,0q�6w   $	��Top=�6�   $	��654��6�      CanUserAddRows .     AutoGenerateColumns .     SelectionMode$ Extended=�6  ��67   �� ��6(  Z� 	   Columns	 5   "   4  .System.Windows.Controls.DataGridCheckBoxColumn  5   &   ,  &System.Windows.Controls.DataGridColumn
   Header$
 选择��6=      Width5  /System.Windows.Controls.DataGridLengthConverter$ * 6I   1  +System.Windows.Controls.DataGridBoundColumn   Binding 6S   �� *
Selected+ �� Mode$ TwoWay=�6   0	  *System.Windows.Controls.DataGridTextColumn	  5    &   $
 查询列名��69   $ * 6G    6Q   �� *ShowField_CN+$ TwoWay=�6�   4
  .System.Windows.Controls.DataGridComboBoxColumn
  5"   &   -   5        dgOP��$
 	操作符��5"   K   $ * 6X    
  DisplayMemberPath$ Value��6b    
  SelectedValuePath$	 Key��6|    
  SelectedValueBinding 6�   �� *OP+6�   4  .System.Windows.Controls.DataGridTemplateColumn  5$   &   $	
 值��6=   $	 200 6H      CellTemplate 5%   *   �� 5&   .   .R�5'   2   �� ��6<   �� *SearchValue+6[   5(   /      CellEditingTemplate 5*   *   �� 5+   .   .R�5,   2   ��  ��Name$ cboValue��6;   -   5        $	��200��5,   f    �� 
IsEditable .  �� SelectedItem 6r   �� *SearchValue+$ TwoWay=� �� Text 6�   �� *SearchValue+6�   5-   /   5/   '   	  51   &   $
 	RealField��69      
Visibility$ Hidden=�6L    6`   �� *	RealField+$ TwoWay=�6�   	  52   &   $
 DataType��69   $ Hidden=�6K    6_   �� *
DataType+$ TwoWay=�6�   54      �� 55      
���   �$��1q�69   $
��Left=�6M   $��47��6h   $��
10,289,0,0q�6t   $	��Top=�6�   $	��654��6�   ._�56   "   � .+�57   &   �� $��查询方案名称:��6,   $
��Left=�6>   $��25��6Y   $��	10,10,0,0q�6e   $	��Top=�6x   $
��auto��6�   �� 58   &   -   5        $��cmbQuery��58   /   $
��Left=�6?   $��25��6Z   $��
110,10,0,0q�6f   $	��Top=�6z   $	��167��6�    . 6�      SFMControls.ButtonSfm  59   &   -	   5        $��btnSave��59   <   $��	保   存��6K   $
��Left=�6[   $��25��6v   $��
303,10,0,0q�6�   $	��Top=�6�   $��88��6�   6�     5:   &   -
   5        $��	btnDelete��5:   <   $��	删   除��6M   $
��Left=�6]   $��25��6x   $��
425,10,0,0q�6�   $	��Top=�6�   $��88��6�   6�   5<   #   5=        5>      -   5        $��	btnSelect��5>   4   $��	查   询��6E   $
��Left=�6U   $��33��6p   $��165,345,0,0q�6|   $	��Top=�6�   $��82��6�   6�     5?      -   5        $��btnExit��5?   4   $��	退   出��6C   $
��Left=�6S   $��33��6n   $��413,345,0,0q�6z   $	��Top=�6�   $��89��6�   6�   5A      5B      5D      5E      �� 5F      $��返回结果��6   ��6$   Z� .��5G      � .+�5H      7  1System.Windows.Forms.Integration.WindowsFormsHost  -   5        $��	wfhVideo2��5H   '    �� Left$ 10��68   
 �� Top$	 465��6I   $��10,10,611,296q�6Z      Child. 5I      %  System.Windows.Forms.PictureBox  -   5        	picIn��"  System.Windows.Forms.Control   Dock$
 Fill=�5I   8      	BackColorU
 QSystem.Drawing, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a# 
 System.Drawing.ColorConverter$ Black 6D      SizeMode$ StretchImage=�6V   5J      5K        5M      -   5        $��dgvCar��5M      $
��Left=�6-   $	��246��6H   $��
10,280,0,0q�6U   $	��Top=�6i   $	��942��6�    .   .     
IsReadOnly . ��6�   Z� 	 5N      	  5O      $
 车辆编号��61      
IsReadOnly .  6?   �� *CardNO+6n   	  5P      $
 车牌号码��61    .  6?   �� *CPH+6k   	  5Q      $
 车辆类型��61    .  6?   �� *ChineseName+6s   	  5R      $
 入场时间��61    .  6?   �� *InTime+  �� StringFormat$  yyyy-MM-dd HH:mm:ss��6�   	  5S      $
 出场时间��61    .  6?   �� *	OutTime+$  yyyy-MM-dd HH:mm:ss��6�   	  5T      $
 收费金额��61    .  6?   �� *SFJE+6l   	  5U      $
 入场名称��61    .  6?   �� *
InGateName+6r   	  5V      $
 出场名称��61    .  6?   �� *OutGateName+6s   	  5W      $
 人员编号��61    .  6?   �� *UserNO+6n   	  5X      $
 人员姓名��61    .  6?   �� *
UserName+6p   	  5Y      $
 余额��61    .  6=   �� *	Balance+6m   	  5Z      $
 应收金额��61    .  6?   �� *YSJE+6l   	  5[      $
 收费时间��61    .  6?   �� *SFTime+$ OneWay=�! �� 	Converter#! [ $  yyyy-MM-dd HH:mm:ss��6�   	  5\      $
 收费人员��61    6?   �� *
SFOperator+6`   	  5]      $
 收费编号��61    .  6?   �� *SFOperatorCard+6v   	  5^      $
 收费口名��61    .  6?   �� *SFGate+6n   	  5_      $
 超时标志��61    .  6?   �� *OvertimeSymbol+6v   	  5`      $
 超时收费时间��61    .  6A   �� *OvertimeSFTime+$ OneWay=�#! [ $  yyyy-MM-dd HH:mm:ss��6�   	  5a      $
 超时收费金额��61    .  6A   �� *OvertimeSFJE+6v   	  5b      $
 车场编号��61    .  6?   �� *	CarparkNO+6q   	  5c      $
 大小标识��61    .  6?   �� *
BigSmall+6p   	  5d      $
 免费原因��61    .  6?   �� *
FreeReason+6r   	  5e      $
 入场人员��61    .  6?   �� *InUser+6n   	  5f      $
 出场人员��61    .  6?   �� *	OutUser+6o   	  5g      $
 入场图片��61    .  6?   �� *InPic+6m   	  5h      $
 出场图片��61    .  6?   �� *OutPic+6n   	  5i      $
 部门名称��61    .  6?   �� *
DeptName+6p   	  5j      $
 证件图片��61    .  6?   �� *ZJPic+6m   	  5k      $
 入场操作编号��61    .  6A   �� *InOperatorCard+6x   	  5l      $
 出场操作编号��61    .  6A   �� *OutOperatorCard+6y   	  5m      $
 入场操作员��61    .  6@   �� *
InOperator+6s   	  5n      $
 出场操作员��61    .  6@   �� *OutOperator+6t   5p      �� 5q      $
��Left=�6!   $��26��6<   $��
10,245,0,0q�6H   $	��Top=�6\   $	��341��6t   " �� Orientation$" 
Horizontal=�6�   $y�	Collapsed=�6�   .+�5r        $��开始回放��60   $
��Left=�6?   $��24��6Z   $��77��6g   $	��0,1q�6r     5s      $��快放��60   $��24��6=   $��0,1,0,0q�6I   $	��Top=�6Z   $��69��6r     5t      $��慢放��60   $��25��6=   $	��Top=�6I   $��60��6a     5u      $��恢复正常��60   $��25��6?   $	��Top=�6K   $��63��6c     5v      $��停止回放��60   $��24��6?   $	��Top=�6K   $��71��6c   5w      � 5x      $
��Left=�6   $	��261��66   $��
386,10,0,0q�6C   $	��Top=�6W   $	��141��6o   # � ColumnDefinitions# 5y      �� 5z      $��* �6/   6;   �� 5{      $��* �6/   6;   $ � RowDefinitions$ 5}      �� 5~      $��* �6,   69   �� 5      $��* �6,   69   �� 5�      $��* �6,   69   �� 5�      $��* �6,   69   �� 5�      $��* �6,   69   �� 5�      $��* �6,   69   �� 5�      $��* �6,   69   �� 5�      $��* �6,   69   .+�5�      �� -   5        $��
月租车:��5�       $��Center=�6/   $
��auto��6L   $��Center=�6[   $
��auto��6v   6�   �� 5�      $��
临时车:��6    $��Center=�6/   $
��auto��6L   $��1��6[   $��Center=�6h   $
��auto��6�   �� 5�      $��
储值车:��6    $��Center=�6/   $
��auto��6L   $��2��6[   $��Center=�6h   $
��auto��6�   �� 5�      $��
免费车:��6    $��Center=�6/   $
��auto��6L   $��3��6[   $��Center=�6h   $
��auto��6�   �� 5�      $��
总车数:��6    $��Center=�6/   $
��auto��6L   $��4��6[   $��Center=�6h   $
��auto��6�   �� 5�      -   5        $��lblMtpCount��5�       $��0��63   $��1��6?   $��Center=�6O   $
��auto��6l   $��Center=�6{   $
��auto��6�   �� 5�      -   5        $��lblTmpCount��5�       $��0��63   $��1��6?   $��Center=�6O   $
��auto��6l   $��1��6{   $��Center=�6�   $
��auto��6�   �� 5�      -   5        $��lblStrCount��5�       $��0��63   $��1��6?   $��Center=�6O   $
��auto��6l   $��2��6{   $��Center=�6�   $
��auto��6�   �� 5�      -   5        $��lblFreCount��5�       $��0��63   $��1��6?   $��Center=�6O   $
��auto��6l   $��3��6{   $��Center=�6�   $
��auto��6�   �� 5�      -   5        $��lblCarCount��5�       $��0��63   $��1��6?   $��Center=�6O   $
��auto��6l   $��4��6{   $��Center=�6�   $
��auto��6�     5�      -   5        $��
btnDelete0��5�   0   $��2��6B   $��删除��6V   $��Center=�6c   $��22��6�   $��5��6�   $��Center=�6�   $	��113��6�   $y�	Collapsed=�6�     5�      -   5        $��btnPrint��5�   0   $��2��6@   $��打印报表��6T   $��Center=�6c   $��22��6�   $��6��6�   $��Center=�6�   $	��113��6�   %   FormName$% 场内车辆查询��6�   &   ItemName$& btnPrint��6�     5�      -   5        $��	btnExport��5�   0   $��导出��6A   $��Center=�6N   $��22��6k   $��7��6x   $��Center=�6�   $	��113��6�   $��2��6�   $% 场内车辆查询��6�   $& 	CmdExport��6�   5�      5�      5�      5�      5�      5�      