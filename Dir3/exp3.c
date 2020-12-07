#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    int fd = open(argv[1], O_EXCL | O_APPEND | O_WRONLY);
    if(fd == -1) {
        printf("Error while opening the file\n");
        exit(0);
    }
    printf("Enter the text to be appended : \n");
    char buffer[100] = {0}, c;
    int i = 0;
    while((c = getchar()) != '\n') {
        buffer[i++] = c;
    }
    int wr = write(fd, buffer, strlen(buffer));
    if(wr == -1) {
        printf("Error writing into file\n");
        exit(0);
    }
    printf("Successfully appended %d characters\n", wr);
    close(fd);
 
}
