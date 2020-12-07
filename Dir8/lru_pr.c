#include <stdio.h>
int arrmin(int [], int ) ;
int arrmin(int a[], int n) 
{
	int i, min = a[0];
	for(i=1; i<n; i++)
		if (min > a[i])
			min = a[i];
	for(i=0; i<n; i++)
		if (min == a[i])
			return i;
	return 0;
}

int main()
{
	int i,j,len,rs[50],frame[10],nf,k,avail,count;
	int access[10], freq=0, dm;
//S1: Get length of the reference string, say l.
	printf("Length of the Reference string :"); 
	scanf("%d", &len);
//S2: Get reference string and store it in an array, say rs.
	printf("Enter the reference string:\n"); 
	for(i=1; i<=len; i++)
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
	for(i=1; i<=len; i++)
	{
	    printf("\n%4d\t",rs[i]); 
	    avail = 0;
	    for(k=0; k<nf; k++)
	    {
//S7: If page exist in memory then Store incremented freq for that page position in access array.
	        if(frame[k] == rs[i])
	        {
	            avail = 1;
	            access[k] = ++freq; 
	            break;
	        }
	    }
	    if(avail == 0)
	    {
	        dm = 0;
	        for(k=0; k<nf; k++)
	        {
	            if(frame[k] == -1) 
	            	dm = 1;
	            break;
	        }
/*S8: If there is an empty frame
	a. assign that frame to the page
	b. Store incremented freq for that page position in access array.
	c. Increment count.*/
	        if(dm == 1)
	        {
	            frame[k] = rs[i];
	            access[k] = ++freq; 
	            count++;
	        }
	        
/*S9: If there is no free frame then
	a. Determine page to be replaced using arrmin function.
	b. Store incremented freq for that page position in access array.
	c. Increment count.*/
	        else
	        {
	            j = arrmin(access,nf);
	            frame[j] = rs[i];
	            access[j] = ++freq;
	            count++;
	        }
	        for(k=0; k<nf; k++)
	            printf("%4d", frame[k]);
	    }
	}
	

//S10: Display pages in frame array.
	printf("\n*\nTotal number of page faults : %d\n*\n", count);
}

