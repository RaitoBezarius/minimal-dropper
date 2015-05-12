#include <dlfcn.h>

#define EXIT(hTable, ReturnCode) ((void (*)(int))call_replacement(hTable, "exit"))(ReturnCode)
#define CRASH(hTable) EXIT(hTable, 1)

#define _PRINT(hTable, string) ((void (*)(const char*))call_replacement(hTable, "printf"))(string)
#define PRINT(hTable, string) _PRINT(hTable, string); \
                            _PRINT(hTable, "\n")

void* initialize_replacement_functions();
void* call_replacement(void* handle, const char* fn_name);
