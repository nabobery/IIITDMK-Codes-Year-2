; Sum of 2 Numbers Using Addressing Modes
; A macro for printing string accepting 2 arguments (%1 , % 2) which are string and length of string respectively
%macro print_string 2 
      mov   eax, 4		; The system call for write (sys_write)
      mov   ebx, 1		; File descriptor 1 - standard output
      mov   ecx, %1		; move offset of 1st argument to ecx
      mov   edx, %2		; move length of 1st argument(2nd argument) to edx
      int   0x80		; call kernel
%endmacro

section .text

global _start

_start:
	print_string msg1, len1           	    
	call direct_offset_relative_addr
	mov edi, temp              ; Argument: Address of the target string
	call int2str               ; Get the digits of EAX and store it as ASCII
	sub edi, temp              ; EDI (pointer to the terminating NULL) - pointer to temp = length of the string
	mov [temp_len], edi
	print_string temp, temp_len 

	; clear the stack and initialise the register values to zero
	xor eax, eax            
    	xor ebx, ebx
    	xor ecx, ecx            
    	xor edx, edx

	print_string msg2, len2           	    
	call indirect_reg_addr
	mov edi, temp              ; Argument: Address of the target string
	call int2str               ; Get the digits of EAX and store it as ASCII
	sub edi, temp              ; EDI (pointer to the terminating NULL) - pointer to temp = length of the string
	mov [temp_len], edi
	print_string temp, temp_len 

	; clear the stack and initialise the register values to zero
	xor eax, eax            
    	xor ebx, ebx
    	xor ecx, ecx            
    	xor edx, edx

	print_string msg3, len3          	    
	call immed_addr
	mov edi, temp              ; Argument: Address of the target string
	call int2str               ; Get the digits of EAX and store it as ASCII
	sub edi, temp              ; EDI (pointer to the terminating NULL) - pointer to temp = length of the string
	mov [temp_len], edi
	print_string temp, temp_len 

	; clear the stack and initialise the register values to zero
	xor eax, eax            
    	xor ebx, ebx
    	xor ecx, ecx            
    	xor edx, edx

	print_string msg4, len4           	    
	call indexed_reg_indirect_addr
	mov edi, temp              ; Argument: Address of the target string
	call int2str               ; Get the digits of EAX and store it as ASCII
	sub edi, temp              ; EDI (pointer to the terminating NULL) - pointer to temp = length of the string
	mov [temp_len], edi
	print_string temp, temp_len 

	; clear the stack and initialise the register values to zero
	xor eax, eax            
    	xor ebx, ebx
    	xor ecx, ecx            
    	xor edx, edx

	print_string msg5, len5           	    
	call auto_inc
	mov edi, temp              ; Argument: Address of the target string
	call int2str               ; Get the digits of EAX and store it as ASCII
	sub edi, temp              ; EDI (pointer to the terminating NULL) - pointer to temp = length of the string
	mov [temp_len], edi
	print_string temp, temp_len 

	; clear the stack and initialise the register values to zero
	xor eax, eax            
    	xor ebx, ebx
    	xor ecx, ecx            
    	xor edx, edx

	print_string msg6, len6          	    
	call auto_dec
	mov edi, temp              ; Argument: Address of the target string
	call int2str               ; Get the digits of EAX and store it as ASCII
	sub edi, temp              ; EDI (pointer to the terminating NULL) - pointer to temp = length of the string
	mov [temp_len], edi
	print_string temp, temp_len 
	
	print_string new_line, new_len	; print new line

_exit :
	mov eax,4                   ; The system call for write (sys_write)
	mov ebx,1                   ; File descriptor 1 - standard output
	mov ecx, new_line           ; move offset of newline to ecx
	mov edx, new_len            ; move length of newline to edx
	int 0x80                    ; call kernel
	mov eax, 1                  ; The system call for exit (sys_exit)
	mov ebx,0                   ; exit with error code 0
	int 0x80                    ; call kernel

;1 Direct Addressing, 4 Direct-Offset Addressing and 5 Relative Addressing Mode
direct_offset_relative_addr: 
      mov eax, [array]      	;move the contents of the array (offset address) to eax (Direct Addressing)
      add eax, [array + 4]  	;using offset to the memory address(relative to memory address which is start of array) of array and add it to eax (Relative Addressing / Direct-Offset Addressing)	  	
      ret

;2 Indirect Addressing and 7 Register Addressing Mode
indirect_reg_addr:
      mov ebx, num                ; move num address to ebx
      add eax, [ebx]		  ; and now access the value using the address and add to eax (Indirect Addressing)
      mov ebx, 100		  ; move 100 to ebx
      add eax, ebx                ; We use the data(100) in register ebx to do the operation (Register Addressing)
      ret		          ; return

;3 Immediate Addressing Mode
immed_addr:
    	mov eax, 50     ; directly store the data into the register (Immediate Addressing Mode)          
    	add eax, 100 	; and do the operation using the register 
	ret	        ; return
               

;6 Indexed Addressing Mode and 8 Register Indirect Addressing   
indexed_reg_indirect_addr:
    	mov esi, array		        ; moving the array's base address to esi       
    	mov eax, [esi] 		        ; move the content (first array element) addressed by esi to eax (Register Indirect Addressing Mode)
    	add eax, [esi + 4]		; using index to access the 2nd array element(Indexed Addressing Mode)         
    	ret				; return

;9 Auto-Increment Addressing Mode
auto_inc:                       
    	mov ebx, array		; store the first array element's address in ebx
    	add eax, [ebx]		; add the 1st array element to eax (eax is 0)
    	add ebx, 4		; go to the next array element(offset increment)
    	add eax, [ebx]		; add the 2nd array element to eax
    	ret
;10 Auto-Decrement Addressing Mode
auto_dec:
      mov ebx, array + 4		; store the second array element's address in ebx
      add eax, [ebx]		        ; add the 2nd array element to eax (eax is 0)
      sub ebx, 4			; go to the previous array element(offset decrement)
      add eax, [ebx]		        ; add the 1st array element to eax
      ret

int2str:    			; Converts an positive integer in EAX to a string pointed to by EDI
    	xor ecx, ecx
    	mov ebx, 10
    	.LL1:                   ; First loop: Save the remainders
        xor edx, edx            ; Clear EDX for div
    	div ebx                 ; EDX:EAX/EBX -> EAX Remainder EDX
    	push dx                 ; Save remainder
    	inc ecx                 ; Increment push counter
    	test eax, eax           ; Anything left to divide?
    	jnz .LL1                ; Yes: loop once more
    	.LL2:                   ; Second loop: Retrieve the remainders
    	pop dx                  ; In DL is the value
    	or dl, '0'              ; To ASCII
    	mov [edi], dl           ; Save it to the string
    	inc edi                 ; Increment the pointer to the string
    	loop .LL2               ; Loop ECX times

    	mov byte [edi], 0       ; Termination character
    	ret                     ; RET: EDI points to the terminating NULL

section .data 
	num dd 50
	array dd 50, 100

	msg1 db 0xA,"Direct, Direct Offset and relative addressing   : "
    	len1 equ $ - msg1 

    	msg2 db 0xA,"InDirect and Register addressing                : "
    	len2 equ $ - msg2

    	msg3 db 0xA,"Immediate addressing                            : "
    	len3 equ $ - msg3

    	msg4 db 0xA,"Register and Indexed Indirect addressing        : "
    	len4 equ $ - msg4

    	msg5 db 0xA,"Auto-Increment addressing                       : "
    	len5 equ $ - msg5

    	msg6 db 0xA,"Auto-Decrement addressing                       : "
    	len6 equ $ - msg6

    	new_line db 0xA                            	        ; new line character
	new_len equ $-new_line                     	        ; length of newline

section .bss
	temp resb 40					 ; for storing num for int2str
	temp_len resd 10				 ; for storing length of num
