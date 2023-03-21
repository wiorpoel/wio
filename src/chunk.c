#include "../include/chunk.h"
#include "../include/memory.h"
#include <stdlib.h>


Chunk * chunk_init() {
    
    Chunk * chunk = (Chunk *) calloc(1, sizeof(Chunk));
    chunk->bytecode = (void *) 0;
    chunk->size = 0;
    chunk->capacity = 0;
    return chunk;
}


void chunk_write(Chunk * chunk, unsigned char byte, unsigned int line) {

    if (chunk->capacity < (chunk->size + 1)) {

        chunk->capacity = MEMORY_INCREASE_CAPACITY(chunk->capacity);
        chunk->bytecode = MEMORY_INCREASE_ARRAY(unsigned char, chunk->bytecode, chunk->capacity);
    }

    chunk->bytecode[chunk->size] = byte;
    chunk->size++;
}


void chunk_free(Chunk * chunk) {

    MEMORY_FREE_ARRAY(chunk->bytecode);
    chunk = chunk_init();
}