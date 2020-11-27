#include <stdio.h>

char format[] = "%s %s\n";
char hello[] = "Hello";
char world[] = "World";

int main()
{
    __asm {
        mov eax, start
        mov ecx, end
        sub ecx, eax
        the_loop:
            mov ebx, [eax]
            xor ebx, 0x23
            mov [eax], ebx
            inc eax
            loop the_loop
        start:
            pushad
            mov  eax, offset world
            push eax
            mov  eax, offset hello
            push eax
            mov  eax, offset format
            push eax
            call printf
            pop  ebx
            pop  ebx
            pop  ebx
            popad
        end:
    }
    return 0;
}