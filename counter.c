#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("%d\n", count_char(STDIN_FILENO));
    } else if(argc == 2){
        FILE *f = fopen(argv[1], "r");
        int fd = fileno(f);
        printf("%d\n", count_char(fd));
        fclose(f);
    } else {
        fprintf(stderr, "Invalid number of arguments");
        exit(EXIT_FAILURE);
    }
    return 0;
}
