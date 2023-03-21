#include "../include/memory.h"
#include <stdlib.h>
#include <stdio.h>


void * memory_allocation(void * pointer, unsigned int size) {
    
    if (size == 0) {

        free(pointer);
        return (void *) 0;
    }

    void * result = realloc(pointer, size);

    if (result == (void *) 0) {

        sprintf(stderr, "%s", "\nError: Not enough memory\n\n");
        exit(1);
    }
    
    return result;
}