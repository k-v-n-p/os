#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    if(argc == 1) {
        printf("File name should be provided in command line only\n");
        printf("E.g. \"./create_and_write file.txt\n\"");
        exit(0);
    }
    int fd = open(argv[1], O_EXCL | O_RDONLY);
    if(fd == -1) {
        printf("Error while opening the file\n");
        exit(0);
    }
    char buffer[100] = {0};
    read(fd, buffer, 5);
    printf("Content of the file is : \n");
    printf("Hello Operating System\n");
    printf("%s", buffer);
    close(fd);
    return 0;
}
