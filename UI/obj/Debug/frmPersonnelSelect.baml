   M S B A M L   `   `   `  ����F  BSFMControls, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null>.clr-namespace:SFMControls;assembly=SFMControlsSFMControls  5   
   >.clr-namespace:SFMControls;assembly=SFMControlsSFMControls  5   	   O Kmscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e0891&clr-namespace:System;assembly=mscorlibSystem 5   	   " 分布式停车场管理系统   UI.frmPersonnelSelect   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   FSFMControls.clr-namespace:SFMControls;assembly=SFMControls     5   
   >src.clr-namespace:SFMControls;assembly=SFMControls     5   	   6sys&clr-namespace:System;assembly=mscorlib     5   	   -   5          � Title$  查询条件��5   	   $	��389��6   $	��420��6#    � 
ResizeMode$ NoResize=�6/      WindowStyle#���   6E    � WindowStartupLocation$ CenterScreen=�6�   .��5      � .+�5	   
   �� -   5        $��	ckbUserNO��5	      $��人员编号   含有��6$   $
��Left=�68   $��20��6S   $��	35,22,0,0q�6_   $	��Top=�6r   $
��auto��6�   6�   �� 5
   
   -   5        $��ckbUserName��5
      $��人员姓名   含有��6&   $
��Left=�6:   $��20��6U   $��	35,57,0,0q�6a   $	��Top=�6t   $
��auto��6�   6�   �� 5   
   -   5        $��ckbDepartment��5      $��部门名称   含有��6(   $
��Left=�6<   $��20��6W   $��	35,96,0,0q�6c   $	��Top=�6v   $
��auto��6�   6�   �� 5   
   -   5        $��ckbHomeAddress��5      $��家庭住址   含有��6)   $
��Left=�6=   $��20��6X   $��
35,137,0,0q�6d   $	��Top=�6x   $
��auto��6�   6�   �� 5   
   -   5        $��	ckbIDCard��5      $��身份证号   含有��6$   $
��Left=�68   $��20��6S   $��
35,180,0,0q�6_   $	��Top=�6s   $
��auto��6�   6�   �� 5   
   -   5        $��ckbMobNumber��5      $��手机号码   含有��6'   $
��Left=�6;   $��20��6V   $��
35,219,0,0q�6b   $	��Top=�6v   $
��auto��6�   6�   �� 5   
   -   5        $��ckbCPH��5      $��车牌号码   含有��6!   $
��Left=�65   $��20��6P   $��
35,254,0,0q�6\   $	��Top=�6p   $
��auto��6�   6�   �� 5   
   -	   5        $��	txtUserNO��5      $
��Left=�6#   $��20��6>   $��
165,21,0,0q�6J    �� TextWrapping$
 Wrap=�6^   $	��Top=�6r   $	��219��6�   6�   �� 5   
   -
   5        $��txtUserName��5      $
��Left=�6%   $��20��6@   $��
165,56,0,0q�6L   $
 Wrap=�6`   $	��Top=�6t   $	��219��6�   6�   �� 5   
   -   5        $��txtDeptName��5      $
��Left=�6%   $��20��6@   $��
165,94,0,0q�6L   $
 Wrap=�6`   $	��Top=�6t   $	��219��6�   6�   �� 5   
   -   5        $��txtHomeAddress��5      $
��Left=�6(   $��20��6C   $��165,136,0,0q�6O   $
 Wrap=�6d   $	��Top=�6x   $	��219��6�   6�   �� 5   
   -   5        $��	txtIDCard��5      $
��Left=�6#   $��20��6>   $��165,179,0,0q�6J   $
 Wrap=�6_   $	��Top=�6s   $	��219��6�   6�   �� 5   
   -   5        $��txtMobNumber��5      $
��Left=�6&   $��20��6A   $��165,218,0,0q�6M   $
 Wrap=�6b   $	��Top=�6v   $	��219��6�   �� 5   
   -   5        $��txtCPH��5      $
��Left=�6    $��20��6;   $��165,254,0,0q�6G   $
 Wrap=�6\   $	��Top=�6p   $	��219��6�      SFMControls.ButtonSfm  5   
   -   5        $��btnSave��5      $��确定��6'   $
��Left=�64   $��24��6O   $��297,294,0,0q�6[   $	��Top=�6p   $��86��6�   6�   5      5      