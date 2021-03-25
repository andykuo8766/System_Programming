#include "apue.h"
#include <signal.h>
#include <time.h>  

void ctrlc (int signum);
void ctrlz (int signum);
void alarming (int signum);
int count_fish = 0;

int rod_ready = 1;
int biting = 0;
int alarm_happening = 0;
int Catched = 0;

/*
struct sigaction {
    void (*sa_handler)(int);
    void (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer)(void);
}
*/
int main(int argc, char *argv[]){
	srand(time(NULL));
	struct sigaction new_action;
	new_action.sa_handler = ctrlc;
	
	struct sigaction new_action2;
	new_action2.sa_handler = ctrlz;
	
	struct sigaction new_action3;
	new_action3.sa_handler = alarming;	
	
		
	sigemptyset (&new_action.sa_mask);
	new_action.sa_flags = 0;

	sigaction(SIGINT, &new_action, NULL);
        
	sigaction(SIGTSTP, &new_action2, NULL);
	
	sigaction(SIGALRM, &new_action3, NULL);
	
    while(1){
		if(rod_ready == 1){
		printf("Fishing rod is ready!\n");
		biting = 0;
		alarm_happening = 0;
		Catched = 0;
		//printf("test\n");
        sleep(15);
		}
	}
	
	return 0;
}

void ctrlc(int signum){
	int time;
    //printf("rev sig=%d\n", signum);
	if(rod_ready == 1){
		printf("\nPut the fishing rod\n");
		printf("Bait into water, waiting fish...\n");
		rod_ready = 0;
		time = rand()%10+1;		
		alarm(time);
		//sleep(5);
	}
	else if(rod_ready == 0){
			printf("\nPull the fishing rod\n");	
			if(alarm_happening==0){
				alarm(0);//cancel alarm					
			}
			else{
				if(biting){
					Catched = 1;
					printf("Catch a Fish!!\n");
					count_fish++;
					printf("Totally caught fishes : %d\n",count_fish);
				}
				else
					printf("The bait was eaten!!\n");
			}
			rod_ready = 1;
		
	}
	
}

void alarming(int signum){
	alarm_happening = 1;
	printf("A fish is bitting,pull the fishing rod\n");
	biting=1;
	sleep(2);
	biting=0;
	if(!Catched)
		printf("The fish was escaped!!\n");
}

void ctrlz(int signum){
	printf("\nTotally caught fishes: %d\n",count_fish);
	exit(0);
}


