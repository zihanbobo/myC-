   M S B A M L   `   `   `  ����Y  U分布式停车场管理系统, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:UIUI  5   	   F BSFMControls, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null>.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	   >.clr-namespace:SFMControls;assembly=SFMControlsSFMControls 5   	   [ WSystem.Windows.Forms, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089Y@clr-namespace:System.Windows.Forms;assembly=System.Windows.FormsSystem.Windows.Forms 5   	       UI.ImageCapture   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35n jSAPBusinessObjects.WPF.ViewerShared, Version=13.0.3500.0, Culture=neutral, PublicKeyToken=692fbea5521e1304H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   !codeclr-namespace:UI     5   	   FSFMControls.clr-namespace:SFMControls;assembly=SFMControls     5   	   >src.clr-namespace:SFMControls;assembly=SFMControls     5   	   Owf@clr-namespace:System.Windows.Forms;assembly=System.Windows.Forms     5   	   -   5          � Title$  摄像头拍照��5   	   $	��400��6   $	��800��6$    � 
ResizeMode$ NoResize=�6G    � WindowStartupLocation$ CenterOwner=�6]   .��5	      � .+�5
   
   7  1System.Windows.Forms.Integration.WindowsFormsHost  $
��Left=�6   $	��288��66   $��4,34,0,0q�6C   $	��Top=�6U   $	��385��6m      Child. 5      %  System.Windows.Forms.PictureBox  -   5        picVideo��5   0   5      �� 5   
   $��	摄像头��6   $
��Left=�6    $��0,10,0,0q�6;   $	��Top=�6M   $	��319��6e   $	��394��6r   �� 5   
   $��照片预览��6   $
��Left=�6!   $��
399,10,0,0q�6<   $	��Top=�6P   $	��319��6h   $	��395��6u   .��5      �� -   5         ��Name$ 
imgCapture��5      $
��Left=�6(   $	��288��6C   $��0,7,0,0q�6P   $	��Top=�6a   $	��385��6y   5        SFMControls.ButtonSfm  5   
   -   5          Name$ 
btnCapture��5       $��拍照��64   $
��Left=�6A   $��487,340,0,0q�6\   $	��Top=�6q   $��75��6�   6�     5   
   -   5        $ btnOK��5       $��确定��6/   $
��Left=�6<   $��591,340,0,0q�6W   $	��Top=�6l   $��75��6�   6�     5   
   -   5        $ 	btnCancel��5       $��取消��63   $
��Left=�6@   $��694,340,0,0q�6[   $	��Top=�6p   $��75��6�   6�   5      5      