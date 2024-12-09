#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
int main(){
	int pid[8];
	pid[0]=fork();
	if(pid[0]==0){
		pid[1]=fork();
		if(pid[1]==0){
			pid[3]=fork();
			if(pid[3]==0){
				pid[7]=fork();
				if(pid[7]==0){
					printf("Hello\n");
				}
				printf("Hello\n");
			}
			pid[6]=fork();
			if(pid[6]==0){
				printf("Hello\n");
			}
			printf("Hello\n");
		}
		pid[4]=fork();
		if(pid[4]==0){
			printf("Hello\n");
		}
		pid[2]=fork();
		if(pid[2]==0){
			pid[5]=fork();
			if(pid[5]==0){
				printf("Hello\n");
			}
			printf("Hello\n");
		}
		printf("Hello\n");
	}
	return 0;
}
