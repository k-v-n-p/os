#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<fcntl.h>
//Step 1: Get filename and search string as command-line argument.
int main(int argc, char *argv[])
{
	char line[750],pat[10],temp;
	int r,j=0;
	int fp;
//step 2: Open the file in read-only mode using open system call.
	fp=open(argv[1],O_RDONLY);
//step 3: If file does not exist, then stop.
	if(fp==-1){
		perror("error opening file");
		exit(EXIT_FAILURE);
		}
//step 4: Let length of the search string be n.
	int n=strlen(argv[2]);
//step 5:Read line-by-line until end-of-file
	if(n==0)
		return 0;
	while((r=read(fp,&temp,sizeof(char)))!=0)
	{
		if(temp !='\n')
		{
			line[j] = temp;
			j++;
		}
		else
		{
			if(strstr(line,argv[2])!=NULL)
				printf("%s\n",line);
			memset(line,0,sizeof(line));
			j=0;
		}
			 
	}
//step 6: Close the file using close system call.
	close(fp);
	return 0;
}
