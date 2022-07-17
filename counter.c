#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "counter.h"
#define BUFFER_SIZE 4096

int count_char(int fd){
    char buffer[BUFFER_SIZE];
    int i = 0;    
    ssize_t num_bytes;

    while ((num_bytes = read(fd, buffer, BUFFER_SIZE))){
        i+= num_bytes;
    }
    return i;
}

void invalid_arguments(){
    fprintf(stderr, "Invalid number of arguments\n");
    exit(EXIT_FAILURE);
}

void invalid_file(){
    fprintf(stderr, "Invalid file: %s\n",strerror(errno));
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
    switch(argc){
        FILE *f;
        case 1:
            printf("%d\n", count_char(STDIN_FILENO));
            break;
        case 2:
            f = fopen(argv[1], "r");
            if (f == NULL){
                invalid_file();
            }
            int fd = fileno(f);
            printf("%d\n", count_char(fd));
            fclose(f);
            break;
        default:
            invalid_arguments();
            break;
    }
    return 0;
}
