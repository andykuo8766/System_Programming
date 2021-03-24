#include <stdio.h>
#include "apue.h"

void accumulation(int d_sum);

int main()
{
	FILE* sum;
	int total_sum=0;
	pid_t pid[5];
	int year=5, week=52, day=7;

	sum = fopen("sum.txt", "w");
	fprintf(sum, "%d\n", 0);
	fclose(sum);

	/**********************************************************/
	FILE* fdata;
	char filename[10];
	int data = 0;
	int i = 0;
	int j = 0;
	int r = 0;
	int c = 0;
	
	TELL_WAIT();
	for(i = 0 ; i <5 ; i++){
		
		
		if ( (pid[i] = fork()) < 0 ) 
			err_sys("fork error");
		else if (pid[i]==0) {   /* child */
			/* child does whatever is necessary */
			WAIT_PARENT(); /* & wait for parent */
			
		
		
			for(j = 1 ; j <= 52; j++){
				sprintf(filename, "%d-%02d.txt", i+1,j);
				fdata = fopen(filename, "r");
				for(r = 1; r <=7; r++){
					for(c = 1 ; c <= 96 ; c++){
						fscanf(fdata, "%d", &data);
						accumulation(data);		
					}
				}
			}
			
			TELL_PARENT(getppid()); /* tell parent we’re done */
			
			
			/* and child continues on its way */
			exit(0);
		}
		/* parent does whatever is necessary */
		TELL_CHILD(pid[i]); /*tell child we’re done */
		WAIT_CHILD(); /* wait for child */
		/* and parent continues on its way */
		//exit(0);
	
	
	}
	


	/**********************************************************/

	sum = fopen("sum.txt", "r");
	fscanf(sum, "%d", &total_sum);
	printf("Day_Average = %d\n",total_sum/(year*week*day));
	fclose(sum);

	return 0;
}

void accumulation(int d_sum)    //Accumulating the daily sum to "sum.txt".
{
	FILE* sum;
	int tmp=0;

	sum = fopen("sum.txt", "r+");
	fscanf(sum, "%d", &tmp);

	tmp += d_sum;

	rewind(sum);
	fprintf(sum, "%d", tmp);
	fclose(sum);

	return;
}
