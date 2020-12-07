#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
void forkprocess() 
{ 
    int x = 1; 
    pid_t rt = fork();
    if (rt == -1){
        printf("process creation unsucceful\n\n");
        return;
       }
    else if (rt==0){
        printf("Child process\n");
        printf("process id of child: %d \n", getpid());
        printf("Value of variable: %d \n", x);
        printf("process id of parent: %d \n\n", getppid());
       }
     else{
     	printf("Parent process\n");
        printf("process id of parent: %d \n", getpid());
        printf("Value of variable: %d \n", getpid());
        printf("Value of variable: %d \n", x);
        printf("process id of Shell: %d \n\n", getppid());
       }
         
} 
int main() 
{ 
    forkprocess(); 
    return 0; 
} 
