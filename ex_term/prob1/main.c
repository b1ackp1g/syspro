#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	printf("type num of childs : ");
	int input, pid[10], child, status;
	scanf("%d", &input);
	for(int i=0;i<input;i++){
		pid[i] = fork();
		if(pid[i]==0){
			printf("[Child %d] : Started! pid=%d, sleep=%d\n", i, getpid(), i+1);
			sleep(i+1);
			printf("[Child %d] : Killed! pid=%d, sleep=%d\n", i, getpid(), i+1);
			exit(0);
		}
	}
	sleep(input);
	child = waitpid(pid[input-1], &status, 0);
	printf("parent killed - last child id = %d\n", child);
}
