; Program template

.386
.model flat,stdcall
.stack 4096

ExitProcess proto,dwExitCode:dword

.data

array1 DWORD 1, 2, 3, 4, 5
array2 DWORD 6, 7, 8, 9, 10
array3 DWORD LENGTHOF array1 dup(?)

.code

main proc

; SWAP

mov eax, array1
mov ebx, array2+16
mov array1, ebx
mov array2+16, eax

mov eax, array1+4
mov ebx, array2+12
mov array1+4, ebx
mov array2+12, eax

mov eax, array1+8
mov ebx, array2+8
mov array1+8, ebx
mov array2+8, eax

mov eax, array1+12
mov ebx, array2+4
mov array1+12, ebx
mov array2+4, eax

mov eax, array1+16
mov ebx, array2
mov array1+16, ebx
mov array2, eax

; ARRAY3

mov eax, array1
mov array3, eax
mov eax, array2
sub array3, eax

mov eax, array1+4
mov array3+4, eax
mov eax, array2+4
sub array3+4, eax

mov eax, array1+8
mov array3+8, eax
mov eax, array2+8
sub array3+8, eax

mov eax, array1+12
mov array3+12, eax
mov eax, array2+12
sub array3+12, eax

mov eax, array1+16
mov array3+16, eax
mov eax, array2+16
sub array3+16, eax

invoke ExitProcess,0
main endp
end main
