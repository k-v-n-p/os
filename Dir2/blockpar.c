#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
	pid_t f = fork();
	if(f == -1){
		printf("Process creation unsucessful\n");
		exit(EXIT_FAILURE);
	}
	if( f > 0){
		wait(NULL);
		printf("Parent starts\n");
		for(int i=0; i<=10; i+=2)
		printf("%d ", i);
		printf("\nParent ends\n");
	}
	if( f == 0){
		printf("Child starts\n");
		for(int i=1; i<=9; i+=2)
		printf("%d ", i);
		printf("\nChild ends\n");
	}
	return 0;;
}
