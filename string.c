#include "string.h"

int string_length(const char* string)
{
    int len = 0;
    while (string[len])
	++len;
    return len;
}

void print(const char* string)
{
    int length = string_length(string);
    asm("movl %0, %%edx;"
	"movl %1, %%ecx;"
	"movl $1, %%ebx;"
	"movl $4, %%eax;"
	"int $0x80;"
	:
	:"r"(length), "a"(string));
}
