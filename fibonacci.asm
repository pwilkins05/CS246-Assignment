; Bugs:
; - line 16: Const UPPER_LIMIT should be 47, not 48
; - FIXED BY MATTHEW BERNIK.....line 54: 'eax' should read 'edx' just like line 58
; - line 146: end of file needs the following line without quotes: "END main"


TITLE	Program 2		(pgm2.asm)
;Author:		Chris Duncan
;Course:		CS298
;Date:		2014-02-06
;Description:	Calculates Fibonacci numbers up to and including a user-entered n-th term.

INCLUDE Irvine32.inc

LOWER_LIMIT EQU 1	;must evaluate at least one term
UPPER_LIMIT EQU 48	;terms larger than 46th overflow DWORD

.data
a		DWORD	1	;first Fibonacci term, by definition
b		DWORD	1	;second Fibonacci term
n		DWORD	?	;number of terms to calculate
sum		DWORD	?	;sum of n terms
intro1	BYTE	"Program 2 - Fibonacci Numbers",0
intro2	BYTE	"Author: Chris Duncan",0
instruct1	BYTE	"Enter a number of terms and this program will calculate",0
instruct2	BYTE	"all the Fibonacci numbers up to and including that term.",0
prompt	BYTE	"Enter a term [1..46]: ",0
error	BYTE	"Term outside range.",0
bye		BYTE	"Thanks for playing along!",0



.code
main	PROC
	call	Intro		;display title and author
	call	Instruct		;display instructions for user
	call	GetData		;get value for limit, validate
	call	Calculate		;loop to add each term
	call	Goodbye		;display exit message
	exit				;exit to operating system
main	ENDP



;Procedure to display intro
;receives: none
;returns: none
;preconditions: none
;registers: edx
Intro	PROC

;print program name line 1
	call Clrscr
	mov edx,OFFSET intro1
	call WriteString
	call Crlf
;print author line 2
	mov edx,OFFSET intro2
	call WriteString
	call Crlf
	call Crlf
	ret
Intro	ENDP



;Procedure to display instructions
;receives: none
;returns: none
;preconditions: none
;registers: edx
Instruct	PROC

;Print instructions line 1
	mov edx,OFFSET instruct1
	call WriteString
	call Crlf
;Print instructions line 2
	mov edx,OFFSET instruct2
	call WriteString
	call Crlf
	call Crlf
	ret
Instruct	ENDP



;Procedure to get value for n from user
;receives: none
;returns: value for n
;preconditions: none
;registers: eax
GetData	PROC

;loop until n within defined range
try:
	mov edx,OFFSET prompt
	call WriteString	;print prompt
	call ReadInt		;get user data
	cmp eax,LOWER_LIMIT	;input < low
	jb inputBad
	cmp eax,UPPER_LIMIT	;input > high
	ja inputBad
	jmp inputOK		;input within range, continue
;print error msg and return to loop
inputBad:
	mov edx,OFFSET error
	call WriteString
	call Crlf
	jmp try
inputOK:
	mov n,eax		;input OK, save to memory
	ret
GetData	ENDP



;Procedure to calculate and display terms
;receives: none
;returns: none
;preconditions: none
;registers: eax
Calculate	PROC

;WORK IN PROGRESS
;Get data from memory into loop counter
	ret
Calculate	ENDP



;Procedure to print goodbye
;receives: none
;returns: none
;preconditions: none
;registers: edx
Goodbye PROC

;Print goodbye message
	mov edx,OFFSET	bye
	call WriteString
	call Crlf
	ret
Goodbye ENDP


