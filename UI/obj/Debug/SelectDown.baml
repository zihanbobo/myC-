   M S B A M L   `   `   `  ����Y  U分布式停车场管理系统, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:UIUI  5   	   F BSFMControls, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null>.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	   >.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	       UI.SelectDown   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   !codeclr-namespace:UI     5   	   FSFMControls.clr-namespace:SFMControls;assembly=SFMControls     5   	   >src.clr-namespace:SFMControls;assembly=SFMControls     5   	   -   5          � Title$  车牌号码下载查询��5   	   $	��525��6   $	��950��6'    � WindowStartupLocation$ CenterScreen=�6J      WindowStyle#���   6o    � 
ResizeMode$ NoResize=�6�    � ShowInTaskbar .  .��5      � .+�5	   
   &   System.Windows.Controls.DataGrid  -   5          Name$ dataGridView1��5	      $��10,10,10,190q�6*   ��6r   Z�    Columns 5
      0  *System.Windows.Controls.DataGridTextColumn  5      ,  &System.Windows.Controls.DataGridColumn   Header$ 车辆编号��6h   1  +System.Windows.Controls.DataGridBoundColumn   Binding 6%   ��  �� Path$ CardNO�	   ClipboardContentBinding	 6E   Z� 6h     5      $ 车牌号码��6e    6%   �� $	 CPH�	 6B   Z� 6e     5      $ 车辆类型��6j    6%   �� $ CardType�	 6G   Z� 6j     5      $ 车辆状态��6r    6%   �� $ CardStateCaption�	 6O   Z� 6r     5      $ 车场有效起日��6�    6%   �� $ CarValidStartDate�
 �� StringFormat$
 
yyyy-MM-dd��	 6i   Z� 6�     5      $ 车场有效止日��6�    6%   �� $ CarValidEndDate�$
 
yyyy-MM-dd��	 6g   Z� 6�     5      $ 下载标识��6o    6%   �� $ DownLoadState�	 6L   Z� 6o     5      $ 车场有效机号��6q    6%   �� $ CarValidMachine�	 6N   Z� 6q     5      $ 车牌下载标识��6s    6%   �� $ CPHDownloadSignal�	 6P   Z� 6s   5      �� 5   
   -   5         ��Name$ listBox1��5      $
��Left=�6$   $	��175��6?   $��	10,0,0,10q�6L   $��Bottom=�6_   $	��714��6z   �� 5   
   -   5         ��Name$ 
ckbOffLine��5      $��脱机车牌下载��6'   $
��Left=�68   $��811,285,0,0q�6S   $	��Top=�6h    d� 	IsChecked$
 TrueY�6�   {�.  6�   �� 5   
   $��车辆编号��6   $
��Left=�6   $��746,316,0,0q�6:   $	��Top=�6O   �� 5   
   $��车牌号码��6   $
��Left=�6   $��746,347,0,0q�6:   $	��Top=�6O   �� 5   
   -   5         ��Name$ 	txtCardNo��5      $
��Left=�6%   $��22��6@   $��811,318,0,0q�6L    �� TextWrapping$
 Wrap=�6a   $�� ��6u   $	��Top=�6}   $	��118��6�   6�   �� 5   
   -   5        $ txtCPH��5      $
��Left=�6"   $��24��6=   $��811,348,0,0q�6I   $
 Wrap=�6^   $�� ��6r   $	��Top=�6z   $	��118��6�   6�     SFMControls.ButtonSfm  5   
   -   5          Name$ 	btnSelect��5       $��
查    询��63   $
��Left=�6D   $��825,393,0,0q�6_   $	��Top=�6t   $��75��6�   6�   5      5      