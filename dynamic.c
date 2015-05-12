#include "dynamic.h"

/*
 * The replacement system will drop in some handles for various usage :
 * 1. handles[0] => libc handle
*/

void* initialize_replacement_functions()
{
    /* void* handlesTable[1]; multiple handles? */
    /* TODO: Drop portable support for dlopen and other things. */
    void* libCHandle = dlopen("libc.so.7", RTLD_LAZY);
    if (!libCHandle)
    {
       /* FIXME: How do we do to escape from the process? */ 
    }

    return libCHandle;
}

void* call_replacement(void* hTable, const char* name)
{
    void* fnPtr = dlsym(hTable, name);
    return fnPtr;
}
