   M S B A M L   `   `   `  ����F  BSFMControls, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null>.clr-namespace:SFMControls;assembly=SFMControlsSFMControls  5   	   [ WSystem.Windows.Forms, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089Y@clr-namespace:System.Windows.Forms;assembly=System.Windows.FormsSystem.Windows.Forms 5   	   O Kmscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e0891&clr-namespace:System;assembly=mscorlibSystem 5   	   " 分布式停车场管理系统   UI.Video.OSDSET_Form   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      5   	   R	 NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml 	    5   	   >src.clr-namespace:SFMControls;assembly=SFMControls 	    5   	   Owf@clr-namespace:System.Windows.Forms;assembly=System.Windows.Forms 	    5   	   6sys&clr-namespace:System;assembly=mscorlib 	    5   	   -   5          � Title$  	OSD设置��5   	   $	��483��6   $	��489��6$      WindowStyle#���   60    � WindowStartupLocation$ CenterScreen=�6q    � 
ResizeMode$ NoResize=�6�   .��5      � .+�5	   
   �� -   5        $��
chkDateWay��5	      $��日期��6%   $
��Left=�62   $
��auto��6M   $��	50,42,0,0q�6[   $	��Top=�6n   $
��auto��6�   �� 5
   
   -   5        $��
chkTimeWay��5
      $��时间��6%   $
��Left=�62   $
��auto��6M   $��
50,132,0,0q�6[   $	��Top=�6o   $
��auto��6�   �� 5   
   -   5        $��
chkWordWay��5      $��文字��6%   $
��Left=�62   $
��auto��6M   $��
50,219,0,0q�6[   $	��Top=�6o   $
��auto��6�   �� 5   
   -   5        $��chkIsUpdateTime��5      $��是否更新时间��6*   $
��Left=�6;   $
��auto��6V   $��
50,295,0,0q�6d   $	��Top=�6x   $
��auto��6�   �� 5   
   $��日期格式:��6   $
��Left=�6    $
��auto��6;   $��
164,37,0,0q�6I   $	��Top=�6]   $
��auto��6u   �� 5   
   -   5        $��
cmbDateWay��5      $
��Left=�6%   $��26��6@   $��
245,37,0,0q�6L   $	��Top=�6`   $	��178��6x    �� 
IsEditable . .@�5      �� .��6   
YYYY/MM/DD6'   �� 5      .��6   
MM/DD/YYYY6'   �� 5      .��6   DD/MM//YYYY6(   5      �� 5   
   $��坐标:��6   $
��Left=�6   $
��auto��69   $��
164,73,0,0q�6G   $	��Top=�6[   $
��auto��6s   �� 5   
   $��X:��6   $
��Left=�6   $
��auto��68   $��
245,73,0,0q�6F   $	��Top=�6Z   $
��auto��6r   �� 5   
   -   5        $��txtDatePosX��5      $
��Left=�6%   $��26��6@   $��
274,73,0,0q�6L    �� TextWrapping$
 Wrap=�6`   $	��Top=�6t   $��54��6�   �� 5   
   $��Y:��6   $
��Left=�6   $
��auto��68   $��
344,73,0,0q�6F   $	��Top=�6Z   $
��auto��6r   �� 5   
   -   5        $��txtDatePosY��5      $
��Left=�6%   $��26��6@   $��
369,73,0,0q�6L   $
 Wrap=�6`   $	��Top=�6t   $��54��6�   �� 5   
   $��时间格式:��6   $
��Left=�6    $��27��6;   $��164,127,0,0q�6G   $	��Top=�6\   $��61��6t   �� 5   
   -	   5        $��
cmbTimeWay��5      $
��Left=�6%   $��26��6@   $��245,128,0,0q�6L   $	��Top=�6a   $	��178��6y    . .@�5      �� .��6   12Hrs6"   �� 5      .��6   24Hrs6"   5      �� 5   
   $��坐标:��6   $
��Left=�6   $
��auto��69   $��164,169,0,0q�6G   $	��Top=�6\   $
��auto��6t   �� 5   
   $��内容:��6   $
��Left=�6   $��27��69   $��164,214,0,0q�6E   $	��Top=�6Z   $��61��6r   �� 5   
   $��坐标:��6   $
��Left=�6   $
��auto��69   $��164,255,0,0q�6G   $	��Top=�6\   $
��auto��6t   �� 5    
   $��X:��6   $
��Left=�6   $
��auto��68   $��245,169,0,0q�6F   $	��Top=�6[   $
��auto��6s   �� 5!   
   -
   5        $��txtTimePosX��5!      $
��Left=�6%   $��26��6@   $��274,169,0,0q�6L   $
 Wrap=�6a   $	��Top=�6u   $��54��6�   �� 5"   
   $��Y:��6   $
��Left=�6   $
��auto��68   $��344,169,0,0q�6F   $	��Top=�6[   $
��auto��6s   �� 5#   
   -   5        $��txtTimePosY��5#      $
��Left=�6%   $��26��6@   $��369,169,0,0q�6L   $
 Wrap=�6a   $	��Top=�6u   $��54��6�   �� 5$   
   -   5        $��
txtWordWay��5$      $
��Left=�6$   $��27��6?   $��245,214,0,0q�6K   $
 Wrap=�6`   $	��Top=�6t   $	��178��6�   �� 5%   
   $��X:��6   $
��Left=�6   $
��auto��68   $��245,255,0,0q�6F   $	��Top=�6[   $
��auto��6s   �� 5&   
   $��Y:��6   $
��Left=�6   $
��auto��68   $��344,255,0,0q�6F   $	��Top=�6[   $
��auto��6s   �� 5'   
   -   5        $��txtWordPosX��5'      $
��Left=�6%   $��26��6@   $��274,255,0,0q�6L   $
 Wrap=�6a   $	��Top=�6u   $��54��6�   �� 5(   
   -   5        $��txtWordPosY��5(      $
��Left=�6%   $��26��6@   $��369,255,0,0q�6L   $
 Wrap=�6a   $	��Top=�6u   $��54��6�   (  "System.Windows.Controls.DatePicker  5)   
   -   5        $��dtDate��5)      $
��Left=�6#   $��31��6>   $��142,329,0,0q�6J   $	��Top=�6_   $	��154��6w   
 �� Now   SelectedDate# Z 6�      SFMControls.ButtonSfm  5*   
   -   5        $��btnSave��5*      $��	保   存��6'   $
��Left=�67   $��26��6R   $��119,377,0,0q�6^   $	��Top=�6s   $��94��6�   6�     5+   
   -   5        $��	btnCancel��5+      $��	取   消��6)   $
��Left=�69   $��26��6T   $��290,377,0,0q�6`   $	��Top=�6u   $��94��6�   6�   7  1System.Windows.Forms.Integration.WindowsFormsHost  5,   
   $��313,329,66,63q�6      Child. 5-      )  #System.Windows.Forms.DateTimePicker  -   5        
dtTime��   Format$
 Time=�5-   0   	   
ShowUpDown	 . 6>   5.      5/      50      