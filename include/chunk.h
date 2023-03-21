#ifndef WIO_CHUNK_H
#define WIO_CHUNK_H


typedef struct CHUNK {

    unsigned char * bytecode;
    unsigned int size;
    unsigned int capacity;
} Chunk;


Chunk * chunk_init();

void chunk_write(Chunk * chunk, unsigned char byte, unsigned int line);
void chunk_free(Chunk * chunk);


#endif