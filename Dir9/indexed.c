#include<stdio.h>
#include<stdlib.h>

int main() 
{ 
	int f[50],i,k,j,inde[50],n,c,count=0,p;
	for(i=0;i<50;i++)
	{
		f[i]=0;
	}
	
	x: printf("enter the index block:\n");
	
	scanf("%d",&p);
	
	if(f[p]==0)
	{ 
		f[p]=1;
		printf("enter no of blocks on index : \n");
		scanf("%d",&n);
	} 
	
	else
	{ 
		printf("Block is already allocated\n"); 
		goto x;
	} 
	printf("enter the datablocks for file to be stored in index : \n");
	for(i=0;i<n;i++)
		scanf("%d",&inde[i]);
		
	 for(i=0;i<n;i++) 
	 {
	 	if(f[inde[i]]==1)
	 	{ 
	 	printf("Block is already allocated\n");
	 	goto x;
	 	} 
	 }
	 	
	 for(j=0;j<n;j++) 
	 	f[inde[j]]=1;
	 		
	 printf("\n allocated");
	 printf("\n file indexed");
	 	
	 for(k=0;k<n;k++)
	 		printf("\n %d->%d:%d",p,inde[k],f[inde[k]]);
	 		
	 	printf("\n");
	 printf("\nDo you want allocate more files (1. yes / 2. no)? : "); 
	 scanf("%d",&c);
	 if(c==1)
	 	goto x;
	 else
	 	exit(0);
	
	 getc(stdin);
	 return 0;
}

