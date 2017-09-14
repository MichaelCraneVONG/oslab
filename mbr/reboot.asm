
;;; shutdown.asm
;;; Shutdown pc
;;;

%define BOOTLOADER

	
%ifdef BOOTLOADER
	org 07c00h
%else
	org 100h
%endif

section .text
	;; ffff0h��ֻ��һ����ת���
	;; dosbox����jmp f000:12c0
	;; 1.�����δʵ��
	;; 2.dosbox�лᵼ������
	;; 3.vbox��Ҳ�ᵼ����������
	jmp 0xffff:0000 

%ifdef BOOTLOADER	
times (512-($-$$) - 2)	db 0 
;;size equ $ - start
;;%if size+2 >512
;;%error "code is too large for boot sector"
;;%endif
db   0x55, 0xAA
%endif
