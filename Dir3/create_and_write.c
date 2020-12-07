#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    char buffer[100] = {0};
    if(argc == 1) {
        printf("File name should be provided in command line only\n");
        printf("E.g. \"./create_and_write file.txt\n\"");
        exit(0);
    }
    int fd = open(argv[1], O_CREAT | O_TRUNC | O_RDWR);
    if(fd == -1) {
        printf("Some error occured while creating file\n");
        printf("Please try again\n");
        exit(0);
    }
    printf("Write something in the file(Press enter to finish entering, max 100 characters) : \n");
    char c;
    int i = 0;
    while((c = getchar()) != '\n') {
        buffer[i++] = c;
    }
    int wr = write(fd, buffer, strlen(buffer));
    if(wr == -1) {
        printf("Error occured while writing in file\n");
        exit(0);
    }
    printf("Successfully entered %d characters in the file\n", wr);
    close(fd);
    return 0;
}
