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

	mov eax, [number] 	    ; set eax to number to calculate number of digits
	mov ecx, 0		    ; intialise ecx to zero as we will be storing number of digits here
	xor edx, edx		    ; make edx zero
	call number_of_digits	    ; function for getting number of digits
	mov eax, [number]	    ; moving number to eax
	call build_armstrong	    ; Function call to build the armstrong sum
	mov eax, [number]	    ; move number to eax
	cmp eax, [sum]		    ; compare armstrong sum and number(in eax)
	je is_armstrong		    ; if it's equal then it's armstrong
	jne not_armstrong	    ; else not an armstrong number 

is_armstrong:
	mov eax,4          	    ; The system call for write (sys_write)
	mov ebx,1          	    ; File descriptor 1 - standard output
	mov ecx,msg1        	    ; move offset of msg to ecx
	mov edx,len1        	    ; move length of msg to edx
	int 0x80           	    ; call kernel
	jmp _exit		    ; jump to exit

not_armstrong:
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

number_of_digits:
	inc ecx			        ; increment everytime a digit is encountered
	mov edx,0		        ; set edx to zero
	mov esi, 10		        ; move 10 to esi which will be used for division
	div esi			        ; divide eax by esi to get the digit
	cmp eax, 0		        ; eax has the quotient if quotient != 0 continue else break
	jnz number_of_digits	        ; continue if eax != 0
	ret			        ; return 

build_armstrong:
	xor edx,edx		        ; set edx to zero 
	mov esi, 10		        ; move 10 to esi which will be used to get the current digit
	div esi			        ; divide eax by esi and store quotient in eax and digit in edx
	
	push eax		        ; store the number we get after dividing with esi (quotient)
	push ecx		        ; push number of digits to stack
	
	mov eax, 1		        ; initialise eax to 1 which will be used for multiplication
	call power		        ; get the power of digit^n and add it to armstrong sum
	
	pop ecx			        ; retrieve number of digits and store it in ecx
	pop eax 		        ; retieve the quotient and store it in eax to continue division
	
	cmp eax, 0		        ; if there's nothing left to divide break the loop else continue
	jnz build_armstrong	        ; continue the loop if eax != 0
	ret			        ; return 


power:
	dec ecx			    ; decrement number of digits
	push edx		    ; push edx to stack so that it can be retrieved after multiplication
	mul edx			    ; multiply edx with eax and store in eax
	pop edx			    ; retrieve the prev edx

	cmp ecx, 0 		    ; if ecx = 0 then exit loop else continue
	jnz power		    ; if ecx != 0 continue loop
	
	mov ecx, [sum]		    ; move the sum calculated till now to ecx
	add eax, ecx		    ; add the current power of digit^n to eax
	mov [sum], eax		    ; now store the curr sum from eax in sum 
	ret			    ; return 
	

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
	msg1 db "The given Number is an Armstrong number", 0xA                  ; string to be printed
	len1 equ $ - msg1				                        ; length of the string
	msg2 db "The given Number is not an Armstrong number", 0xA              ; string to be printed
	len2 equ $ - msg2				                        ; length of the string
	new_line db 0xA                            	                        ; new line character
	new_len equ $-new_line                     	                        ; length of newline
	number dd 1634                                      	                ; number taken is 1634
	sum dd 0						                ; for storing the armstrong sum


section .bss
	num resb 40			 	 ; for storing num for int2str
	num_len resd 10				 ; for storing length of num
