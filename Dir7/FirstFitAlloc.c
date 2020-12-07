#include <stdio.h>

//Step 1: Declare structures hole and process to hold information about set of holes and processes respectively.
struct process {
	int size;
	int flag;
	int holeid;
} p[10];
struct hole {
	int size;
	int actual;
} h[10];

int main() {
	int i, np, nh, j;
//Step 2: Get number of holes(nh), size of each hole, number of processes(np), memory requirements for each process.
	printf("Enter the number of Holes : "); 
	scanf("%d", &nh);
	for(i=0; i<nh; i++) {
		printf("Enter size for hole H%d : ",i); 
		scanf("%d", &h[i].size);
		h[i].actual = h[i].size;
	}
	printf("\nEnter number of process : "); 
	scanf("%d", &np);
	for(i=0; i<np; i++) {
		printf("Enter the size of process P%d : ", i); 
		scanf("%d", &p[i].size);
		p[i].flag = 0;
	}
//Step 3: For each hole if hole size > process size then mark process as allocated to that hole and decrement hole size by process size.
	for(i=0; i<np; i++) {
		for(j=0; j<nh; j++) {
			if(p[i].flag != 1 && p[i].size <= h[j].size) {
				p[i].flag = 1;
				p[i].holeid = j;
				h[j].size -= p[i].size;
			}
		}
	}
	
	printf("\n\tFirst Fit Allocation\n");
	printf("\nProcess\tPSize\tHole");
//Step 4: Print the list of process and list of holes, along eith their status and allocation.
	for(i=0; i<np; i++) {
		if(p[i].flag != 1)
			printf("\nP%d\t%d\tNot allocated", i, p[i].size); 
		else
			printf("\nP%d\t%d\tH%d", i, p[i].size, p[i].holeid);
	}
	printf("\n\nHole\tActual\tAvailable");
	for(i=0; i<nh; i++)
		printf("\nH%d\t%d\t%d", i, h[i].actual, h[i].size); 
	printf("\n");
	return 0;
}
