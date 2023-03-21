#include "../include/io.h"
#include <string.h>
#include <stdio.h>


int main(int argc, const char * argv[]) {


    if (argc == 2) {

        char length = (char) strlen(argv[1]);
        const char * extension = &argv[1][length - 4];

        if (!strcmp(extension, ".wio")) {

            const char * content = io_read_file(argv[1]);
            printf("%s", content);
        }
    } 
    return 0;
}