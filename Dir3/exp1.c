#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    char buffer[100] = {0};
    int fd = open(argv[1], O_CREAT | O_TRUNC | O_RDWR);
    if(fd == -1) {
        printf("Some error occured while creating file\n");
        printf("Please try again\n");
        exit(0);
    }
    printf("Enter the text for the contents of file : \n");
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
    printf("File successfully created and entered %d characters.\n", wr);
    close(fd);
    return 0;
}
