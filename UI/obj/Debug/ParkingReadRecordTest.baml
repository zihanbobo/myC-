   M S B A M L   `   `   `  ����F  BSFMControls, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null>.clr-namespace:SFMControls;assembly=SFMControlsSFMControls  5   	   >.clr-namespace:SFMControls;assembly=SFMControlsSFMControls  5   	   O KMyUserControlLibrary, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullY@clr-namespace:MyUserControlLibrary;assembly=MyUserControlLibraryMyUserControlLibrary 5   	   " 分布式停车场管理系统   UI.ParkingReadRecordTest   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   FSFMControls.clr-namespace:SFMControls;assembly=SFMControls     5   	   >src.clr-namespace:SFMControls;assembly=SFMControls     5   	   aMyUserControlLibrary@clr-namespace:MyUserControlLibrary;assembly=MyUserControlLibrary     5   	   -   5          � Title$  提取记录��5   	   $	��360��6   $	��780��6#      WindowStyle#���   6/    � 
ResizeMode$ NoResize=�6U    � WindowStartupLocation$ CenterScreen=�6k   .��5      � ��5	   
   �� 5
       �� EndPoint$ 0.5,1&�6"    �� 
StartPoint$ 0.5,0&�63   .��5      �  � Color$ 	#FF399ADE��6    � Offset$ 0Q�61   � 5      $ White��6   $ 1Q�6-   5      .+�5   
   -  'MyUserControlLibrary.WaitingAndProgress  -   5          Name$ pgbShow��5   2   $
��Left=�6C   $	��247��6^   $��	10,36,0,0q�6k   $	��Top=�6~   $	��747��6�      ShowType$ WaitingAndProgress=�6�   �� 5   
   -   5        $��	tbkLoding��5      $
��Left=�6%   $
��auto��6@   $��	10,11,0,0q�6N   $��NoWrap=�6a   $��正在加载...��6w   $	��Top=�6�   $
��auto��6�   �� 5   
   $
��Left=�6   $
��auto��6/   $��
104,11,0,0q�6=   $��NoWrap=�6Q   $��车道名称:��6g   $	��Top=�6t   $
��auto��6�   �� 5   
   -   5        $��lblLaneName��5      $��Label��6#   $
��Left=�63   $
��auto��6N   $��	160,5,0,0q�6\   $	��Top=�6o   $��64��6�   �� 5   
   $
��Left=�6   $
��auto��6/   $��
278,11,0,0q�6=   $��NoWrap=�6Q   $��	车道IP:��6g   $	��Top=�6t   $
��auto��6�   �� 5   
   -   5        $��	lblLaneIP��5      $��Label��6!   $
��Left=�61   $
��auto��6L   $��	321,5,0,0q�6Z   $	��Top=�6m   $	��110��6�   �� 5   
   $
��Left=�6   $
��auto��6/   $��
464,11,0,0q�6=   $��NoWrap=�6Q   $��车道机号:��6g   $	��Top=�6t   $
��auto��6�   �� 5   
   -   5        $��lblLaneNumber��5      $��Label��6%   $
��Left=�65   $
��auto��6P   $��	529,5,0,0q�6^   $	��Top=�6q   $��88��6�   �� 5   
   $
��Left=�6   $
��auto��6/   $��
641,11,0,0q�6=   $��NoWrap=�6Q   $��
记录数:��6g   $	��Top=�6s   $
��auto��6�   �� 5   
   -   5        $��lblRecordCount��5      $��Label��6&   $
��Left=�66   $
��auto��6Q   $��	685,5,0,0q�6_   $	��Top=�6r   $��72��6�   5      5      