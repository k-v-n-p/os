#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>

 
//Step 0: Assume no. of blocks in the disk as 20 and all are free.
int num=0, length[10], start[10]; 
char fid[20][4], a[20][4];


void directory()
{
	int i;
	printf("\nFile Start Length\n");
	for(i=0;i<num; i++)
	printf("%-4s %3d %6d\n",fid[i],start[i],length[i]);
}


void display()
{
	int i;
	for(i=0; i<20; i++)
		printf("%4d",i);
	printf("\n"); 
	
	for(i=0;i<20; i++)
		printf("%4s", a[i]);
}
int main()
{
	int i,n,k,temp,st,nb,ch,flag; char id[4];
	
	for(i=0; i<20; i++)
		strcpy(a[i], "");
	printf("Disk space before allocation:\n"); 
	//Step 1: Display the status of disk blocks before allocation.
		display();
	do
	{
		//Step 2: Get the filename, start address and file length
		printf("\nEnter File name (max 3 char) : ");
		scanf("%s",id);
		printf("Enter the start block : ");
		scanf("%d", &st);
		printf("Enter the number of blocks : ");
		scanf("%d", &nb);
		strcpy(fid[num], id);
		length[num] = nb;
		flag = 0;
		//Step 3: If start + length > 20, then goto step 1.
		if((st+nb) > 20)
		{
			printf("Requirement exceeds range\n");
			continue;
		}
		

		for(i=st; i<(st+nb); i++)
			if(strcmp(a[i], "") != 0)
				flag = 1;
		//Step 4: Check to see whether any block in the range (start, start + length-1) is allocated. If so, then go to step 1.	
		if(flag == 1)
		{
			printf("Contiguous allocation not possible.\n"); 
			continue;
		}
		
		start[num] = st;
		
		for(i=st;i<(st+nb); i++)
			strcpy(a[i], id);
		//Step 5: Allocate blocks to the file contiguously from start block to start + length – 1.
		printf("Allocation done\n");
		num++;
		printf("\nDo you want allocate more files (1. yes / 2. no)? : "); 
		scanf("%d",&ch);
	} 
	while (ch == 1);
	printf("\n\t\t\t***Contiguous Allocation***\n");
	printf("Directory:");
	directory();
	//Step 6:  Display directory entries.
	printf("\nDisk space after allocation:\n");
	display();
	printf("\n");
	return 0;
}
