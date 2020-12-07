#include<stdio.h>

struct process {
	int pid, btime, wtime, ttime;
};

void sort(struct process p[], int n)	{
	for(int i=0; i<n; i++)	{
		for(int j=0; j<n-1; j++)	{
			if(p[j+1].btime < p[j].btime)	{
				struct process temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
}

int main()	{
	int n;
	printf("Enter the number of processes : ");
	scanf("%d", &n);
	struct process p[n];
	printf("Enter the burst time of the processes\n\n");
	printf("Processes   \t\tBurst time\n");
	for(int i=0; i<n; i++)	{
		p[i].pid = i+1;
		printf("Process %d \t:\t", i+1);
		scanf("%d", &p[i].btime);
	}
	sort(p, n);
	p[0].wtime = 0;
	for(int i=0; i<n; i++)	{
		if(i < n-1)	{
			p[i+1].wtime = p[i].wtime + p[i].btime;
		}
		p[i].ttime = p[i].wtime + p[i].btime;
	}
	float awat = 0, atur = 0;
	printf("\n\nProcesses  \t\tBurst time\tTurn-around Time   Waiting Time\n");
	for(int i=0; i<n; i++)	{
		printf("Process %d\t\t  %d\t\t  %d\t\t \t%d\n", p[i].pid, p[i].btime, p[i].ttime, p[i].wtime); 
		awat += p[i].wtime;
		atur += p[i].ttime;
	}
	awat /= n;
	atur /= n;
	printf("\nAverage Waiting Time = %f\n", awat);
	printf("\nAverage Turn-around Time = %f\n", atur);
	printf("\nGantt Chart\n   ");
	int i, j;
    int last = p[n-1].btime + ( n== 1 ? 0 : p[n-1].wtime);

    printf("\n|");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].btime-1; j++) printf(" ");
        printf("p%d", p[i].pid);
        for(j=0; j<p[i].btime-1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");

    for(i=0; i<n; i++) {
        for(j=0; j<p[i].btime; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    int minus = 0;
    for(i=0; i<n; i++) {
        if(p[i].wtime>9) printf(" ");
        printf("%d", p[i].wtime);
        if(p[i+1].wtime>9){
          minus = 1;
        }
        if(i+1 == n )  if (last>9) minus = 1;
        for(j=0; j<p[i].btime-minus; j++) printf("  ");

    }
    if(last>9) printf(" ");
    printf("%d\n", last);
	printf("\n");
}

