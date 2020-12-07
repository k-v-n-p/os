#include <stdio.h>
int main()
{
	int i,j,l,rs[50],frame[10],nf,k,avail,count;
//S1: Get length of the reference string, say l.
	printf("Enter the length of ref. string :");
	scanf("%d", &l);
//S2: Get reference string and store it in an array, say rs.
	printf("Enter the reference string:\n"); 
	for(i=1; i<=l; i++)
		scanf("%d", &rs[i]);
//S3: Get number of frames, say nf.
	printf("Enter the number of frames :"); 
	scanf("%d", &nf);
//S4: Initalize frame array upto length nf to ‐1.
	for(i=0; i<nf; i++)
		frame[i] = -1;
//S5: Initialize position of the oldest page, say j to 0.
	j = 0;
//S6: Initialize no. of page faults, say count to 0.
	count=0;
	printf("\nReference string Page frames :");
	for(i=1; i<=l; i++)
	{
		printf("\n%4d\t",rs[i]); 
		avail = 0;
		for(k=0; k<nf; k++)
		//S7 Check whether page exist in the frame array
			if(frame[k] == rs[i])
				avail = 1;
/*S8: If it does not exist the
	a. Replace page in position j.
	b. Compute page replacement position as (j+1) modulus nf.
	c. Increment count by 1.
	d. Display pages in frame array.
	h. Print count.
*/
		if(avail == 0)
		{
			frame[j] =rs[i];
			j = (j+1) % nf;
			count++;
			for(k=0; k<nf; k++)
				printf("%4d", frame[k]);
		}
	}
//S9: Print count.
	printf("\n*\nTotal no. of page faults : %d\n*\n",count);
	return 0 ;
}
