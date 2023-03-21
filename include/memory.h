#ifndef WIO_MEMORY_H
#define WIO_MEMORY_H


#define MEMORY_INCREASE_CAPACITY(capacity) ((capacity < 8) ? 16 : capacity * 2)
#define MEMORY_INCREASE_ARRAY(type, pointer, size) (type *) memory_allocation(pointer, size)
#define MEMORY_FREE_ARRAY(pointer) memory_allocation(pointer, 0)


void * memory_allocation(void * pointer, unsigned int size);


#endif