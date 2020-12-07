#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main ()
{
    pid_t pid;
//step 1: Decalre a array pfd with two elements for pipe descriptors and
    int pfd[2];
    int i, j, flag, f1, f2, f3;
//Declare a array to store fibonacci numbers
    static unsigned int ar[25], br[25];
    
    if (pipe (pfd) == -1)
    {
      printf ("Error in pipe");
      exit (-1);
    }
//step 2: Using fork system call, create a child process.
    pid = fork ();
    
    if (pid == 0)
    {
      printf ("Fibonacci series is generated by child process:\n");
      f1 = -1;
      f2 = 1;
//step 3: Let the child process generate 25 fibonacci numbers and store them in a array.
        for (i = 0; i < 25; i++)
	{
	  f3 = f1 + f2;
	  printf ("%d\t", f3);
	  f1 = f2;
	  f2 = f3;
	  ar[i] = f3;
	}
        write (pfd[1], ar, 25 * sizeof (int));
    }
  
    else if (pid > 0)
    {
//step 5: Block the parent till child completes using wait system call.
      wait (NULL);
      read (pfd[0], br, 25 * sizeof (int));
      printf ("\nPrime numbers among fibonacci by parent process are: \n");
      
        for (i = 0; i < 25; i++)
	{
	  flag = 0;
	  
	  if (br[i] <= 1)
	    flag = 1;
//Step 6: Inspect each element of the fibonacci array and check whether they are prime
	    for (j = 2; j <= br[i] / 2; j++)
	    {
	    
	        if (br[i] % j == 0)
		{
		  flag = 1;
		  break;
		}
	    }
	    
	    if (flag == 0)
	      printf ("%d\t", br[i]);
	}
      printf ("\n");
    }
    else
    {
      printf ("Process creation failed");
      exit (-1);
    }
}


