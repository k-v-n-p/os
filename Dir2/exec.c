#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char **argv){
    if(argc == 3) {
        exit(0);
    }
    int ret = fork();
    if(ret == -1) {
        printf("Process creation unsuccessful\n");
        exit(0);
    }
    if(ret > 0) {
        wait(0);
        printf("Child Terminated\n");
        exit(0);
    }
    else {
        printf("Child starts\n");
        char *args[] = {"./exec1", NULL};
        execvp(args[0], args);
        exit(0);
    }
}
