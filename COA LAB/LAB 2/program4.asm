; A macro for printing string accepting 2 arguments (%1 , % 2) which are string and length of string respectively
%macro print_string 2 
      mov   eax, 4
      mov   ebx, 1
      mov   ecx, %1
      mov   edx, %2
      int   80h
%endmacro

section .text

global _start

_start:
	mov eax, len 		; move string length which includes spaces to eax
	mov [chars], eax	; store the result in chars
	mov ecx, eax 		; character counter used for traversing the string
	mov ebx, 0		; vowel counter initialised to zero
	mov edx, 0		; words counter initialised to zero
	mov esi, 0		; Adsress pointer counter initialised to zero
	
	jmp process		; go to process and start the computation 

space_increment:
    	inc  edx			; increment number of words
    	dec  ecx			; decrement number of characters to be read
    	inc  esi    		        ; increment the Address pointer

process:
     	mov al, [input + esi]		        ; go to the esi(th) char in the string by using esi as offset
	cmp al, ' '			        ; compare current char with space
	je space_increment		        ; if it's a space then call space_increment
	
	vowel:				        ; else we check if it's a vowel
          cmp al, 'a'		            ; check if it's one of the vowels
          je vowel_increment	            ; if it's equal increment the number of vowels

          cmp al, 'e'		            ; check if it's one of the vowels
          je vowel_increment	            ; if it's equal increment the number of vowels

          cmp al, 'i'		            ; check if it's one of the vowels
          je vowel_increment	            ; if it's equal increment the number of vowels

          cmp al, 'o'		            ; check if it's one of the vowels
          je vowel_increment	            ; if it's equal increment the number of vowels

          cmp al, 'u'		            ; check if it's one of the vowels
          je vowel_increment	            ; if it's equal increment the number of vowels

          cmp al, 'A'		            ; check if it's one of the vowels
          je vowel_increment	            ; if it's equal increment the number of vowels

          cmp al, 'E'		            ; check if it's one of the vowels
          je vowel_increment	            ; if it's equal increment the number of vowels

          cmp al, 'I'		            ; check if it's one of the vowels
          je vowel_increment	            ; if it's equal increment the number of vowels

          cmp al, 'O'		            ; check if it's one of the vowels
          je vowel_increment	            ; if it's equal increment the number of vowels

          cmp al, 'U'		            ; check if it's one of the vowels
          je vowel_increment	            ; if it's equal increment the number of vowels

          jmp counter_increment	            ; else increment the counter
		
          vowel_increment:
              inc ebx

          counter_increment:
              inc esi
	loop process			        ; loop over process until ecx != 0

; Calculations and storage of values
	inc edx 		        ; to include the last word
	mov [words],edx			; move the word counter to store it in the variable
	
	mov [vowels], ebx		; move the vowel counter to store it in the variable
	
	mov eax, [chars]		; move number of characters to eax
	sub eax, [words]		; subtract number of words which is spaces + 1
	sub eax, [vowels]		; subtract number of vowels
	inc eax 			; to get back that extra space
	mov [consonants], eax	        ; store the consonant counter in the variable
	
	print_string msg1, len1
	print_string input, len
	print_string new_line, new_len
	
	print_string msg2, len2
	mov eax, [words]
	mov edi, temp              ; Argument: Address of the target string
	call int2str               ; Get the digits of EAX and store it as ASCII
	sub edi, temp              ; EDI (pointer to the terminating NULL) - pointer to num = length of the string
	mov [temp_len], edi
	print_string temp, temp_len
	print_string new_line, new_len

	xor edx, edx		      ; reset edx to zero after int2str

	print_string msg3, len3
	mov eax, [chars]
	mov edi, temp              ; Argument: Address of the target string
	call int2str               ; Get the digits of EAX and store it as ASCII
	sub edi, temp              ; EDI (pointer to the terminating NULL) - pointer to num = length of the string
	mov [temp_len], edi
	print_string temp, temp_len
	print_string new_line, new_len

	xor edx, edx		       ; reset edx to zero after int2str

	print_string msg4, len4
	mov eax, [vowels]
	mov edi, temp              ; Argument: Address of the target string
	call int2str               ; Get the digits of EAX and store it as ASCII
	sub edi, temp              ; EDI (pointer to the terminating NULL) - pointer to num = length of the string
	mov [temp_len], edi
	print_string temp, temp_len
	print_string new_line, new_len

	xor edx, edx		       ; reset edx to zero after int2str

	print_string msg5, len5
	mov eax, [consonants]
	mov edi, temp              ; Argument: Address of the target string
	call int2str               ; Get the digits of EAX and store it as ASCII
	sub edi, temp              ; EDI (pointer to the terminating NULL) - pointer to num = length of the string
	mov [temp_len], edi
	print_string temp, temp_len
	print_string new_line, new_len
	
	call _exit                  ; exit the program


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
	input db "My Name is Avinash"					; string to be printed
	len equ $-input							; length of the string
	msg1 db "Given String is " 					; string to be printed
	len1 equ $-msg1							; length of the string
	msg2 db "number of words: "					; string to be printed
	len2 equ $-msg2							; length of the string
	msg3 db "number of characters: "				; string to be printed
	len3 equ $-msg3							; length of the string
	msg4 db "number of vowels: "					; string to be printed
	len4 equ $-msg4							; length of the string
	msg5 db "number of consonants: "				; string to be printed
	len5 equ $-msg5							; length of the string
	new_line db 0xA                            	                ; new line character
	new_len equ $-new_line                     	                ; length of newline

	words   dd 0
	chars   dd 0
	vowels  dd 0
	consonants dd 0

segment .bss
	temp resb 40				; for storing num for int2str
	temp_len resd 10			; for storing length of num
