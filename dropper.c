int string_length(char* message)
{
    int len = 0;
    while (message[len])
	++len;
    return len;
}

void print(char* message)
{
    int length = string_length(message);
    asm("movl %0, %%edx;"
	"movl %1, %%ecx;"
	"movl $1, %%ebx;"
	"movl $4, %%eax;"
	"int $0x80;"
	:
	:"r"(length), "a"(message));
}

void _start()
{
    print("Hey!\n");
    asm("movl $1, %eax;"
    "xorl %ebx,%ebx;"
    "int $0x80;"
    );
}
