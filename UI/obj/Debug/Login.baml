   M S B A M L   `   `   `  ����F  BSFMControls, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null>.clr-namespace:SFMControls;assembly=SFMControlsSFMControls  5   	   >.clr-namespace:SFMControls;assembly=SFMControlsSFMControls  5   	   " 分布式停车场管理系统   UI.Login   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   FSFMControls.clr-namespace:SFMControls;assembly=SFMControls     5   	   >src.clr-namespace:SFMControls;assembly=SFMControls     5   	   Adx2http://schemas.devexpress.com/winfx/2008/xaml/core     5   	   -   5          � Title$  登录��5   	      WindowStyle#���   6   $	��349��6:   $	��417��6G    � WindowStartupLocation$ CenterScreen=�6S    � 
ResizeMode$ NoResize=�6x   $��15(�6�    � Icon$ Resources/Park.ico��6�      SFMControls.WindowBase   HeaderFontSize$ 24Q�6�   .��5      �  � RowDefinitions 5	   
   �� 5
      $
��0.2* �6   6,   �� 5      $��* �6   6)   �� 5      $��* �6   6)   �� 5      $��* �6   6)   �� 5      $��* �6   6)   �� 5      $��* �6   6)   �� 5      $��* �6   6)    � ColumnDefinitions 5   
   �� 5      $	��52* �6   6-   �� 5      $
��104* �6   6.   �� 5      $
��120* �6   6.   �� 5      $	��88* �6   �� 5      $	��53* �6   6-   .+�5   
   �� $��用户姓名:��6   $��Center=�6    $��Center=�6=   $��15(�6X   $��1��6f   $��1��6v   $��13,10q�6�   �� 5   
   $��用户密码:��6   $��Center=�6    $��Center=�6=   $��15(�6X   $��2��6f   $��1��6s   $��13,10q�6�   G� 5   
   -   5         G�Name$ txtPwd��5      $��Center=�6&   $
��auto��6C   $��Center=�6Q   $	��178��6l   $��15(�6x   $��2��6�   $��2��6�   
������ $��2��6�   $��15,12q�6�   �� 5   
   $��工作站名:��6   $��Center=�6    $��Center=�6=   $��15(�6X   $
��auto��6f   $��3��6t   $��1��6�   $
��13,9q�6�      SFMControls.ButtonSfm  5   
   -   5          Name$ btnLogin��5       $��登      录��62   $��Center=�6E   $��Center=�6b   $	��280��6}   $��1��6�   $��4��6�   $��3��6�   $��	16,7,16,8q�6�   �� 5   
   -   5        	 ��Name$	 cbbStationId��5      $��Center=�6)   $��Center=�6F   $	��178��6a   $��15(�6m   $
��auto��6{   $��2��6�   $��3��6�   
������ $��2��6�   $��15,11q�6�   �� 5   
   -   5        $��
chkParkSet��5      $��登陆进入车场设置��6%   $��Right=�68   $��20��6T   $��Center=�6a   $	��114��6|   $��2��6�   $��
0,38,14,35q�6�   $��12(�6�   $��2��6�   $��2��6�   $y�Hidden=�6�   �� 5    
   -   5        $	 cbbUserName��5       $��2��6(   $��Center=�68   $��1��6U   $��Center=�6b   $	��178��6}   
������ $��15(�6�   $��2��6�   $��15,11q�6�     5!   
   -   5        $��btnSet��5!   !   $��服务参数设置��6/   $��1��6@   $��Center=�6P   $��6��6m   $��Center=�6z   $	��280��6�   $��3��6�   $��	16,8,16,7q�6�     5"   
   -   5        $��
btnParkSet��5"   !   $��车场设置��63   $��1��6B   $��Center=�6R   $��5��6p   $��Center=�6}   $	��280��6�   $��3��6�   $y�Visible=�6�   $
��16,7q�6�   5#      5$      