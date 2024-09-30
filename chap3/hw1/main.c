#include <stdio.h>
#include "copy.h"

char line[4][MAXLINE];
char longest[MAXLINE];

int main(){
	int len;
	int max;
	int count = 0;
	int max_num;
	max = 0;

	while(count <5){
		gets(line[count]);
		len = strlen(line[count]);
		if(len > max)
			count++;
	}

	while(count >=0){
		max = 0;
		for(int i=0;i<5;i++){
			if((len = strlen(line[i])) > max){
				max = len;
				copy(line[i], longest);
				max_num = i;
			}
		}

		if(max > 0)
			printf("%s \n", longest);

		line[max_num][0] = '\0';
		count--;
	}
	return 0;
}
