
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main ()
{
//1. Decalre a array pfd with two elements for pipe descriptors.
    int pfds[2];
//2. Create pipe on pfd using pipe function call.
    pipe (pfds);
//3. Using fork system call, create a child process.
//4. Free the standard output (1) using close system call to redirect the output to pipe.
    if (!fork ())
    {
      close (1);
//5. Make a copy of write end of the pipe using dup system call.
      dup (pfds[1]);  
      close (pfds[0]);
//6. Execute who command using execlp system call.
      execlp ("who", "who", NULL);  
    }
    else  //7.Free the standard input (0) using close system call in the other process.
    {
      close (0);
//8. Make a close of read end of the pipe using dup system call.
      dup (pfds[0]);
      close (pfds[1]);
//9. Execute wc –l command using execlp system call.
      execlp ("wc", "wc", "-l", NULL);
    }
}


