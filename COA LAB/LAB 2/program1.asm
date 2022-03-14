section .text
	global _start

_start:
	mov eax,4          	    ; The system call for write (sys_write)
	mov ebx,1          	    ; File descriptor 1 - standard output
	mov ecx,msg        	    ; move offset of msg to ecx
	mov edx,len        	    ; move length of msg to edx
	int 0x80           	    ; call kernel
	
	mov eax, [number]	   ; moving number to eax for printing
	mov edi, num               ; Argument: Address of the target string
	call int2str               ; Get the digits of EAX and store it as ASCII
	sub edi, num               ; EDI (pointer to the terminating NULL) - pointer to num = length of the string
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

        xor dx,dx                   ; setting dx to 0 after calling int2str
	mov eax, [number]	    ; moving number to eax
	mov ebx,2 		    ; move 2 to ebx
	div ebx		            ; eax is divide by ebx which is 2
	mov ecx, eax		    ; we'll be checking divisors from (largest divisor)num/2 to 2(least divisor)
		     
check_prime :
	xor edx,edx 		    ; setting edx to 0 
	mov eax, [number]	    ; moving number to eax
	div ecx 		    ; dividing number(eax) with ecx
	dec ecx		            ; decrement the divisor and going to the next divisor(in decreasing order)
	cmp edx,0 		    ; checking if remainder is 0
	je not_prime   		    ; if the number is divisible by a number other than itself or 1 it's not prime

	cmp ecx, 1		        ; checking if we have reached 1
	je prime		        ; it means that number is only divisble by only itself so therefore prime
	
	mov eax, [number]	    ; we move number to eax 
	cmp eax, [number] 	    ; we haven't reached the yet
	je check_prime		    ; so continue the loop until it breaks
	
prime :
	mov eax,4          	    ; The system call for write (sys_write)
	mov ebx,1          	    ; File descriptor 1 - standard output
	mov ecx,msg1        	    ; move offset of msg to ecx
	mov edx,len1        	    ; move length of msg to edx
	int 0x80           	    ; call kernel
	jmp _exit		    ; jump to exit  

not_prime :	
	mov eax,4          	    ; The system call for write (sys_write)
	mov ebx,1          	    ; File descriptor 1 - standard output
	mov ecx,msg2                ; move offset of msg to ecx
	mov edx,len2                ; move length of msg to edx
	int 0x80           	    ; call kernel
	jmp _exit	            ; jump to exit


_exit :
	mov eax, 1    ; The system call for exit (sys_exit)
	mov ebx,0     ; exit with error code 0
	int 0x80      ; call kernel

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
	msg db "Given Number is "			                	; string to be printed
	len equ $ - msg 			                        	; length of the string
	msg1 db "The given Number is a prime", 0xA    				; string to be printed
	len1 equ $ - msg1				                      	; length of the string
	msg2 db "The given Number is not a prime", 0xA				; string to be printed
	len2 equ $ - msg2				                      	; length of the string
	new_line db 0xA                            	  			; new line character
	new_len equ $-new_line                     	  			; length of newline
	number dd 997                                 				; num is 997

section .bss
	num resb 40					; for storing num for int2str
	num_len resd 10				 	; for storing length of num
