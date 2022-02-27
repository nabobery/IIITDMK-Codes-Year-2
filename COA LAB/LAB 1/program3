section .text

global _start

_start:
  mov eax,4          ; The system call for write (sys_write)
	mov ebx,1          ; File descriptor 1 - standard output
	mov ecx,msg        ; move offset of msg to ecx
	mov edx, len       ; move length of msg to edx
	int 0x80           ; call kernel
	
	mov ebx, [num]
	mov eax, 1
_loop:
    mul ebx
    dec ebx
    cmp ebx,0
    je print;
    loop _loop
	
print:	
	  mov edi, result                ; Argument: Address of the target string
    call int2str                   ; Get the digits of EAX and store it as ASCII
    sub edi, result                ; EDI (pointer to the terminating NULL) - pointer to sum = length of the string
    mov [result_len], edi
    
    mov eax,4                   ; The system call for write (sys_write)
    mov ebx,1                   ; File descriptor 1 - standard output
	  mov ecx, result             ; move offset of num to ecx
	  mov edx, [result_len]       ; move length of num to edx
	  int 0x80                    ; call kernel
	
	  mov eax,4                   ; The system call for write (sys_write)
	  mov ebx,1                   ; File descriptor 1 - standard output
	  mov ecx, new_line           ; move offset of newline to ecx
	  mov edx, new_len            ; move length of newline to edx
	  int 0x80                    ; call kernel

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
    .LL2:                   ; Second loop: Retrieve the remainders
    pop dx                  ; In DL is the value
    or dl, '0'              ; To ASCII
    mov [edi], dl           ; Save it to the string
    inc edi                 ; Increment the pointer to the string
    loop .LL2               ; Loop ECX times

    mov byte [edi], 0       ; Termination character
    ret                     ; RET: EDI points to the terminating NULL


section .data
    msg db  'The Factorial of 10 is '           ; string to be printed
    len equ $ - msg                             ; Length of the string
    new_line: db 0xA                            ; new line character
	  new_len: equ $-new_line                     ; lenght of newline
	  num dd 10

segment .bss
    result resb 40
    result_len resd 5
