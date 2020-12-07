#include<stdio.h>
#include <string.h> 

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

int main() {

    int n;
    struct process p[100];
    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));

    //cout << setprecision(2) << fixed;

   printf("Enter the number of processes: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++) {
        printf("Enter arrival time of process %d:  ",i+1);
        scanf("%d",&p[i].arrival_time);
        printf("Enter burst time of process %d:  ",i+1);
        scanf("%d",&p[i].burst_time);
        printf("Enter priority of the process %d:  ",i+1);
        scanf("%d",&p[i].priority);
        p[i].pid = i+1;
        printf("\n");
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while(completed != n) {
        int idx = -1;
        int mx = -1;
        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && is_completed[i] == 0) {//if same fcfs
                if(p[i].priority > mx) {
                    mx = p[i].priority;
                    idx = i;
                }
                if(p[i].priority == mx) {
                    if(p[i].arrival_time < p[idx].arrival_time) {
                        mx = p[i].priority;
                        idx = i;
                    }
                }
            }
        }
        //waiting_time for 1st process taken as zero
        if(idx != -1) {
            p[idx].start_time = current_time;
            p[idx].completion_time = p[idx].start_time + p[idx].burst_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            p[idx].response_time = p[idx].start_time - p[idx].arrival_time;
            
            total_turnaround_time += p[idx].turnaround_time;
            total_waiting_time += p[idx].waiting_time;
            total_response_time += p[idx].response_time;
            total_idle_time += p[idx].start_time - prev;

            is_completed[idx] = 1;
            completed++;
            current_time = p[idx].completion_time;
            prev = current_time;
        }
        else {
            current_time++;
        }
        
    }

    int min_arrival_time = 10000000;
    int max_completion_time = -1;
    for(int i = 0; i < n; i++) {
        min_arrival_time = min(min_arrival_time,p[i].arrival_time);
        max_completion_time = max(max_completion_time,p[i].completion_time);
    }

    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;


    
    printf("\n\nProcesses  \tATime \tBtime \tPriority\tTTime \tWtime \tCompletionTime\n");
    for(int i = 0; i < n; i++) {
        	printf("  %d  \t\t%d \t%d \t%d \t\t%d \t%d \t%d \n",p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].turnaround_time, p[i].waiting_time, p[i].completion_time);
    }
    printf("\nAverage Turnaround Time = %f \n",avg_turnaround_time);
    printf("Average Waiting Time = %f \n", avg_waiting_time);
    
    printf("\nGantt Chart\n   ");
	int i, j;
    int last = p[n-1].burst_time + ( n== 1 ? 0 : p[n-1].waiting_time);

    printf("\n|");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time-1; j++) printf(" ");
        printf("p%d", p[i].pid);
        for(j=0; j<p[i].burst_time-1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");

    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    int minus = 0;
    for(i=0; i<n; i++) {
        if(p[i].waiting_time>9) printf(" ");
        printf("%d", p[i].waiting_time);
        if(p[i+1].waiting_time>9){
          minus = 1;
        }
        if(i+1 == n )  if (last>9) minus = 1;
        for(j=0; j<p[i].burst_time-minus; j++) printf("  ");

    }
    if(last>9) printf(" ");
    printf("%d\n", last);
	printf("\n");

	return 0;
}
