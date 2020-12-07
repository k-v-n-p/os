#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int f[50], p,i, st, len, j, c, k, a;
	char id[4];
	
	for(i=0;i<50;i++)
		f[i]=0;
		
	printf("Enter how many blocks already allocated: ");
	scanf("%d",&p);
	if(p!=0)
		printf("Enter blocks already allocated: ");
	
	for(i=0;i<p;i++)
	{
		scanf("%d",&a);
		f[a]=1;
	}
	
	x :printf("\nEnter File name (max 3 char) : ");
	scanf("%s",id);
	printf("Enter index starting block and length: ");
	scanf("%d%d", &st,&len);
	k=len;
	
	if(f[st]==0)
	{
		for(j=st;j<(st+k);j++)
		{
			if(f[j]==0)
			{
				f[j]=1;
				printf("%d ------> %s\n",j,id);
			}
			
			else
			{
				printf("%d datablock allocated to different file \n",j);
				k++;
			}
		}
	}
	
	else
		printf("%d Starting block is already allocated \n",st);
	printf("\nDo you want allocate/continue adding files (1. yes / 2. no)? : "); 
	scanf("%d", &c);
	if(c==1)
		goto x;
	else
		exit(0);
	getc(stdin);
}

