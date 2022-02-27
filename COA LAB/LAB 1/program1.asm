section .text

global _start

_start:
    mov eax, [num1] ; move first num to ecx
 	cmp eax, [num2] ; compare num1 and num2
    jg check_third  ; if num1 > num2
    mov eax, [num2] ; else move num2 to ecx
    
    check_third:
        cmp eax, [num3] ; compare ecx and num3
        jg check_fourth ; if num in ecx > num3
        mov eax, [num3] ; else move num3 to ecx
    
    check_fourth:
        cmp eax, [num4] ; compare ecx and num4
        jg check_fifth  ; if num in ecx > num4
        mov eax, [num4] ; else move num4 to ecx
    
    check_fifth: 
        cmp eax, [num5] ; compare ecx and num4
        jg _exit        ; if num in ecx > num5
        mov eax, [num5] ; else move num5 to ecx
    
_exit:
    ; Convert the number to a string
    mov edi, largest                ; Argument: Address of the target string
    call int2str                    ; Get the digits of EAX and store it as ASCII
    sub edi, largest                ; EDI (pointer to the terminating NULL) - pointer to sum = length of the string
    mov [largest_len], edi
    mov eax,4          ; The system call for write (sys_write)
	mov ebx,1          ; File descriptor 1 - standard output
	mov ecx,msg        ; move offset of msg to ecx
 	mov edx, len       ; move length of msg to edx
 	int 0x80           ; call kernel
 	
    mov eax,4               ; The system call for write (sys_write)
	mov ebx,1               ; File descriptor 1 - standard output
    mov ecx, largest        ; move offset of largest to ecx
    mov edx, [largest_len]  ; move length of largest to edx
    int 0x80                ; call kernel
 	
    mov eax, 1    ; The system call for exit (sys_exit)
    mov ebx,0     ; exit with error code 0
    int 0x80      ; call kernel
    
int2str:    ; Converts an positive integer in EAX to a string pointed to by EDI
    xor ecx, ecx
    mov ebx, 10
    .LL1:                   ; First loop: Save the remainders
    xor edx, edx            ; Clear EDX for div
    div ebx                 ; EDX:EAX/EBX -> EAX Remainder EDX
    push dx                 ; Save remainder
    inc ecx                 ; Increment push counter
    test eax, eax           ; Anything left to divide?
    jnz .LL1                ; Yes: loop once more
    .LL2:                       ; Second loop: Retrieve the remainders
    pop dx                  ; In DL is the value
    or dl, '0'              ; To ASCII
    mov [edi], dl           ; Save it to the string
    inc edi                 ; Increment the pointer to the string
    loop .LL2               ; Loop ECX times

    mov byte [edi], 0       ; Termination character
    ret                     ; RET: EDI points to the terminating NULL

section .data
	msg:     db 'The largest number is: ',0xA    ; printing out string
	len:  equ $-msg                              ; Length of the string
	num1 dd 150  ;first number 
	num2 dd 420  ;second number
	num3 dd 525  ;third number
	num4 dd 750  ;fourth number
	num5 dd 800  ;fifth number

section .bss
  largest resb 40
  largest_len resd 1
