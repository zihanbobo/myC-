   M S B A M L   `   `   `  ����Y  U分布式停车场管理系统, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:UIUI  5   	   F BSFMControls, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null>.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	   >.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	       UI.WhiteList_Form   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   !codeclr-namespace:UI     5   	   FSFMControls.clr-namespace:SFMControls;assembly=SFMControls     5   	   >src.clr-namespace:SFMControls;assembly=SFMControls     5   	   -   5          � Title$  	白名单��5   	   $��621.888��6   $	��800��6&      WindowStyle#���   6M   .��5      � .+�5	   
     SFMControls.ButtonSfm  -   5          Name$ changebt��5	      $��修改��6*   $
��Left=�67   $��	64,19,0,0q�6R   $	��Top=�6e   $��80��6}   6�     5
   
   -   5        $ deletebt��5
      $��删除��6*   $
��Left=�67   $��
173,19,0,0q�6R   $	��Top=�6f   $��80��6~   6�     5   
   -   5        $ button1��5      $��删除所有��6)   $
��Left=�68   $��
278,19,0,0q�6S   $	��Top=�6g   $��80��6   6�   �� 5   
   -   5         ��Name$ 
searchtext��5      $
��Left=�6&   $��23��6A   $��
425,19,0,0q�6M    �� TextWrapping$
 Wrap=�6a   $�� ��6u   $	��Top=�6}   $	��120��6�     5   
   -   5        $ searchbt��5      $��查询��6*   $
��Left=�67   $��
550,19,0,0q�6R   $	��Top=�6f   $��80��6~   6�   &   System.Windows.Controls.DataGrid  5   
   -   5          Name$ dgList��5      $��10,69,10,55q�6#      HorizontalGridLinesBrush �	#FFE0E0E0   VerticalGridLinesBrush �	#FFE0E0E0��6�   Z�    Columns 5      0  *System.Windows.Controls.DataGridTextColumn  5      ,  &System.Windows.Controls.DataGridColumn   Header$ 	车牌 ID��6h   1  +System.Windows.Controls.DataGridBoundColumn	   Binding	 6%   �� 
 �� Path$
 CardNO�   ClipboardContentBinding 6E   Z� 6h     5      $ 	车牌号��6e   	 6%   �� $	
 CPH� 6B   Z� 6e     5      $ 过期时间��6i   	 6%   �� $
 EndDate� 6F   Z� 6i   4  .System.Windows.Controls.DataGridCheckBoxColumn  5      $ 是否启用��6o   	 6)   �� $
 	IsEnabled� 6L   Z� 6o     5      $ 是否报警��6m   	 6)   �� $
 IsAlarm� 6J   Z� 6m   5      �� 5   
   -   5         ��Name$ lblStep��5      $��0 / 0��6!   $��0,0,0,10q�61   $��Bottom=�6C   $��Center=�6^     5   
   -	   5        $ button2��5      $��	上一页��6)   $��Right=�67   $��0,0,70,8q�6S   $��Bottom=�6e   6�     5   
   -
   5        $ button3��5      $��	下一页��6)   $��Right=�67   $��0,0,10,8q�6S   $��Bottom=�6e   6�     5   
   -   5        $ addbt��5      $��添加��6'   $
��Left=�64   $��
670,19,0,0q�6O   $	��Top=�6c   $��67��6{   $y�Hidden=�6�   5      5      