#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<fcntl.h>

#define BUFFER_SIZE 1024

//Step 1: Get source and destination filename as command-line argument.
int main(int argc, char* argv[]) 
{ 
    
    int source, destination; 
    //Step 2: Declare a buffer of size 1KB
    char *buff[BUFFER_SIZE];
    source=open(argv[1],O_RDONLY);
    //step 3: If file does not exist, then stop.
    if(source==-1){
    	perror("Error in opening source file\n");
    	exit(EXIT_FAILURE);
    }
    //step 4: Create the destination file using creat system call.
    destination=creat(argv[2],S_IWUSR);
    //step 5: If file cannot be created, then stop.
    if (destination== -1) 
    { 
        perror("Error in opening destination file\n");
    	exit(EXIT_FAILURE);
    }
    //step 6: File copy achieved by given algo.
    int n=read(source,buff,BUFFER_SIZE);
    if(n<=0){
        perror("Error in reading from source file\n");
    	exit(EXIT_FAILURE);
   }
    while (n>0) 
    { 
        if(write(destination,buff,BUFFER_SIZE)!=n){
        	
    		exit(EXIT_FAILURE);
        }
    } 
  //Step 8: Close source and destination file using close system call.
    close(source); 
    close(destination); 

    return 0; 
}
