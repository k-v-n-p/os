
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

int main(int c, char *v[]) {
    DIR *myDirectory;
    struct dirent *myFile;
 
        myDirectory = opendir(v[1]);
        if (myDirectory) 
        {
            puts("Directory containes the files: \n");
            while ((myFile = readdir(myDirectory)))
                printf("%s\n", myFile->d_name);

            if (closedir(myDirectory) == 0)
                printf("The directory is now closed.\n");
            else
                printf("The directory can not be closed.\n");
        } 
        else if (errno == ENOTDIR)
            printf("This file is not a directory.\n");
        else if (errno == EACCES)
            printf("You do not have the right to open this folder.\n");
        else
         	printf("Error reading contents.\n");
         	

 
    return (0);
}
