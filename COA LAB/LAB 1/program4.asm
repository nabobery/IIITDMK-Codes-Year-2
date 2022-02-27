section .text

global _start

_start:
	mov eax,4          ; The system call for write (sys_write)
	mov ebx,1          ; File descriptor 1 - standard output
	mov ecx, msg       ; move offset of msg to ecx
	mov edx, len       ; move length of msg to edx
	int 0x80           ; call kernel
	
	mov esi, 7         ; pointer for storing index of array
	xor eax, eax       ; initialising eax to 0 which will be storing our sum
	
sum_loop:
    mov ebx,DWORD [array + esi*4-4] ; move the data from current index to ebx (int is 4 bytes so multiplying by 4)
    add eax, ebx                    ; addiing element to eax
    dec esi                         ; decrement the index and proceed
    test esi,esi                    ; seeing if esi is zero
    jz exit                         ; if equal to zero then exit
    loop sum_loop                   ; continue with the loop is esi != 0
	
exit:
	  mov edi, sum                    ; Argument: Address of the target string
    call int2str                    ; Get the digits of EAX and store it as ASCII
    sub edi, sum                    ; EDI (pointer to the terminating NULL) - pointer to sum = length of the string
    mov [sum_len], edi
    
    mov eax,4                   ; The system call for write (sys_write)
	  mov ebx,1                   ; File descriptor 1 - standard output
  	mov ecx, sum                ; move offset of sum to ecx
	  mov edx, sum_len            ; move length of sum to edx
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
	msg:  db 'The sum of array elements is '    ; string + newline character
	len:  equ $-msg 		                        ; Length of the string
	size dd 7                                   ; array size
	array dd 20,40,60,80,100,120,140            ; array elements and intialisation
	

segment .bss
	sum resb 40             ; for storing sum
	sum_len resd 10         ; for storing length of sum


