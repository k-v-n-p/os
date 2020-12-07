#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc,char **argv) 
{ 
	struct dirent **namelist; 
	char directory_name[256] = {'\0'};
//step 1: Store path of current working directory using getcwd system call.
	if(getcwd(directory_name, sizeof(directory_name)) != NULL) {
	    printf ("Created\n");
	} 
	else {
	    printf ("Failed, error getting current directory.\n");
	}
	int n;
	if(argc < 1) {
	 exit(EXIT_FAILURE); 
	} 
//step 2: Scan directory of the stored path using scandir system call 
// and sort the resultant array of structure.
	else if (argc == 1) {
		n=scandir(".",&namelist,NULL,alphasort); 
	} 
	else {
		n = scandir(argv[1], &namelist, NULL, alphasort); 
	} 
//step 3: Display dname member for all entries if it is not a hidden file.
	if(n>=0)
	{ 
		while (n--) { 
			printf ("%s\n",namelist[n]->d_name); 
			free(namelist[n]); 
		} 
		free(namelist); 
	} 
	else {
		perror("scandir"); exit(EXIT_FAILURE); 
	} 
	exit(EXIT_SUCCESS); 
	return 0;
}
