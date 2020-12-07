
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) 
{ 
//Step 1: Get filename as command-line argument.



	FILE *f1;
	char  c;
	
//Step 2: Open the file in read-only mode using read system call.
	f1 = fopen(argv[1], "r");
	
//Step 3: If file does not exist, then stop.
	if (f1 == NULL) {
		perror("Error opening the file\n");
		exit(0);
	}

//Step 4: Close the file using close system call.
	fclose(f1);
//Step 5: Delete the file using unlink system call.
	int status = unlink(argv[1]);
	
	if (status == 0) {
	 printf ("Deleted successfully\n");
	 exit (0);
	}
	return 0;

	
}
