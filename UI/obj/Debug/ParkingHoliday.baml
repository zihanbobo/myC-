   M S B A M L   `   `   `  ����Y  U分布式停车场管理系统, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:UIUI  5   	   O Kmscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e0891&clr-namespace:System;assembly=mscorlibSystem 5   	       UI.ParkingHoliday   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   !codeclr-namespace:UI     5   	   6sys&clr-namespace:System;assembly=mscorlib     5   	   -   5          � Title$,  &节假日设置(仅用于深圳收费)��5   	   $	��429��6    $	��690��6-    � 
ResizeMode$ NoResize=�6P    � WindowStartupLocation$ CenterScreen=�6f      WindowStyle#���   6�   .��5      � .+�5   
   �� $��假日设置��6   $
��Left=�6!   $	��337��6<   $��	10,10,0,0q�6I   $	��Top=�6\   $	��315��6t   .��5	      � .+�5
      �� $��假日列表:��6   $
��Left=�6(   $
��auto��6C   $��10,9,0,0q�6Q   $	��Top=�6c   $
��auto��6{   �� 5      -   5        $��
lstHoliday��5      $
��Left=�6,   $	��266��6G   $��	10,39,0,0q�6T   $	��Top=�6g   $	��139��6   �� 5      $��日期:��6   $
��Left=�6&   $
��auto��6A   $��
143,10,0,0q�6O   $	��Top=�6c   $
��auto��6{   (  "System.Windows.Controls.DatePicker  5      -   5        $��	dtHoliday��5      $
��Left=�6.   $��
185,10,0,0q�6I   $	��Top=�6]   $	��105��6u   
 �� Now   SelectedDate# Z 6�   �� 5      -   5        $��btnAddHoliday��5      $��添  加��6.   $
��Left=�6=   $��26��6X   $��
189,76,0,0q�6d   $	��Top=�6x   $��93��6�   6�   �� 5      -   5        $��btnDeleteHoliday��5      $��删  除��61   $
��Left=�6@   $��26��6[   $��189,120,0,0q�6g   $	��Top=�6|   $��93��6�   6�   �� 5      $`��Z请添加除星期六和星期日以外的日期，星期六和星期日默认为假日。��6   $
��Left=�6B   $��75��6]   $��172,187,0,0q�6i   $	��Top=�6~   $	��110��6�   $
��Wrap=�6�   5      5      �� 5   
   $��工作日设置��6   $
��Left=�6"   $	��337��6=   $��
365,10,0,0q�6J   $	��Top=�6^   $	��298��6v   .��5      � .+�5      �� $��工作日列表:��6   $
��Left=�6)   $
��auto��6D   $��	10,10,0,0q�6R   $	��Top=�6e   $
��auto��6}   �� 5      -   5        $��lstWork��5      $
��Left=�6)   $	��264��6D   $��	10,41,0,0q�6Q   $	��Top=�6d   $	��132��6|   �� 5      -   5        $��btnAddWorkDay��5      $��添  加��6.   $
��Left=�6=   $��26��6X   $��
183,75,0,0q�6d   $	��Top=�6x   $��93��6�   6�   �� 5      -   5        $��btnDeleteWorkDay��5      $��删  除��61   $
��Left=�6@   $��26��6[   $��183,118,0,0q�6g   $	��Top=�6|   $��93��6�   6�   �� 5      $��日期:��6   $
��Left=�6&   $
��auto��6A   $��	129,9,0,0q�6O   $	��Top=�6b   $
��auto��6z     5      -	   5        $��dtWork��5      $
��Left=�6+   $��26��6F   $��
171,10,0,0q�6R   $	��Top=�6f   $	��105��6~   # Z 6�   �� 5      $x��r请添加需要上班的星期六或星期日（例如国庆前的双休日如果要上班，则需在此添加）��6   $
��Left=�6J   $��83��6e   $��165,185,0,0q�6q   $
��Wrap=�6�   $	��Top=�6�   $	��111��6�   5      5      5      5       