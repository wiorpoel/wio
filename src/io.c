#include "../include/io.h"
#include <stdio.h>
#include <stdlib.h>


const char * io_read_file(const char * filepath) {
    
    char * buffer;
    unsigned long length;
    FILE * file = fopen(filepath, "rb");

    if (file) {
        
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);

        buffer = (char *) calloc(1, length + 1);

        if (buffer) {

            if (length != fread(buffer, 1, length, file)) {

                free(buffer);
                printf("\nwio: Error: '%s': File read error\n\n", filepath);
                exit(1);
            }

            fclose(file);
            buffer[length] = '\0';
            return buffer;
        }

        printf("\nwio: Error: '%s': Not enough memory to read file\n\n", filepath);
        exit(1);
    }

    printf("\nwio: Error: '%s': No such file\n\n", filepath);
    exit(1);
}