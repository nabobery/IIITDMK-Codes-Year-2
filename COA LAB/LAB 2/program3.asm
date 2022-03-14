section .text

global _start

_start:
	mov eax,4          	        ; The system call for write (sys_write)
	mov ebx,1          	        ; File descriptor 1 - standard output
	mov ecx,msg        	        ; move offset of msg to ecx
	mov edx,len        	        ; move length of msg to edx
	int 0x80           	        ; call kernel
	
	mov eax, [number]	    ; moving number to eax for printing
	mov edi, num                ; Argument: Address of the target string
	call int2str                ; Get the digits of EAX and store it as ASCII
	sub edi, num                ; EDI (pointer to the terminating NULL) - pointer to num = length of the string
	mov [num_len], edi
    
	mov eax,4                   ; The system call for write (sys_write)
	mov ebx,1                   ; File descriptor 1 - standard output
	mov ecx, num                ; move offset of result to ecx
	mov edx, [num_len]          ; move length of result to edx
	int 0x80                    ; call kernel

	mov eax,4                   ; The system call for write (sys_write)
	mov ebx,1                   ; File descriptor 1 - standard output
	mov ecx, new_line           ; move offset of newline to ecx
	mov edx, new_len            ; move length of newline to edx
	int 0x80                    ; call kernel
	
	xor edx, edx 		        ; make edx zero after calling int2str
	mov eax, [number]	        ; moving number to eax
	xor ecx, ecx		        ; intialise ecz to zero which will be used to store number of digits

get_digits:
	inc ecx			            ; increase ecx as we encounter a digit
	mov esi, 10		            ; move 10 to esi which will be used for division
	xor edx, edx		            ; make edx zero
	div esi			            ; divide eax by 10 and store quotient in eax
	push edx		            ; push digit onto to the stack
	cmp eax, 0		            ; if there's nothing left to divide stop, else continue
	jnz get_digits		            ; continue if eax != 0
	
	xor edx, edx 		            ; make edx zero
	mov esi, 1		            ; initialise esi to 1 which contains pow(10) to be multiplied with digit
	mov ebx, 1		            ; initialise ebx to 1 which contains 10

build_rev_num:
	dec ecx			            ; decrement the number of digits as we build the number in reverse
	mov eax, esi		            ; mov esi to eax
	mul ebx			            ; multiply ebx with eax and store in eax
	mov esi, eax	  	            ; move eax to esi
	mov ebx, 10		            ; move 10 to ebx
	pop eax			            ; store the current digit in eax
	mul esi 		            ; multiply eax with esi
	mov edx, [reverse_num]	            ; move current build of reverse num to edx
	add edx, eax		            ; add the current digit to edx
	mov [reverse_num], edx	            ; move back the current reverse_num from edx to reverse_num 
	cmp ecx, 0		            ; compare number of digits left with 0
	jnz build_rev_num	            ; if not 0 then continue else break

check_palindrome:
	mov eax, [number]		    ; move num to eax
	cmp eax, [reverse_num]	  	    ; compare reverse number with eax if equal then a palindrome else not
	jne not_palindrome		    ; if not equal then call not_palindrome

is_palindrome:
	mov eax,4          	    ; The system call for write (sys_write)
	mov ebx,1          	    ; File descriptor 1 - standard output
	mov ecx,msg1        	    ; move offset of msg to ecx
	mov edx,len1        	    ; move length of msg to edx
	int 0x80           	    ; call kernel
	jmp _exit		    ; jump to exit

not_palindrome:
	mov eax,4          	    ; The system call for write (sys_write)
	mov ebx,1          	    ; File descriptor 1 - standard output
	mov ecx,msg2        	    ; move offset of msg to ecx
	mov edx,len2        	    ; move length of msg to edx
	int 0x80           	    ; call kernel
	jmp _exit	            ; jump to exit

_exit :
	mov eax, 1    ; The system call for exit (sys_exit)
	mov ebx,0     ; exit with error code 0
	int 0x80      ; call kernel

int2str:    			        ; Converts an positive integer in EAX to a string pointed to by EDI
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
	msg db "Given Number is "			                        ; string to be printed
	len equ $ - msg 			                                ; length of the string
	msg1 db "The given Number is a Palindrome", 0xA                         ; string to be printed
	len1 equ $ - msg1				                        ; length of the string
	msg2 db "The given Number is not a Palindrome", 0xA                     ; string to be printed
	len2 equ $ - msg2				                        ; length of the string
	new_line db 0xA                            	                        ; new line character
	new_len equ $-new_line                     	                        ; length of newline
	number dd 123321                                   	                ; number taken is 123321
    reverse_num dd 0						                ; for storing the reverse number


section .bss
	num resb 40			 	 ; for storing num for int2str
	num_len resd 10				 ; for storing length of num

;Example :
;Number : 1234 
;Stack : 4 3 2 1 (top is 1)
;now we build by doing 1*1 + 2*10 + 3*100 + 4*1000
