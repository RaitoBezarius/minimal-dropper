#include "string.h"

void _start()
{
    print("Hey!\n");
    asm("movl $1, %eax;"
    "xorl %ebx,%ebx;"
    "int $0x80;"
    );
}
