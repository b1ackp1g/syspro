#include <stdio.h>
int main(int argc, char *argv[]){
	FILE *fp;
	int count = 1;
	int n=0;
	char c;
	if(argc > 1 && strcmp(argv[count], "-n") == 0){
		count++;
		n = 1;
	}
	while(count < argc){
		if(n == 1)
			printf("%d ", count-1);
		fp = fopen(argv[count], "r");
		while((c = getc(fp)) != EOF)
			putc(c, stdout);
		fclose(fp);
		count++;
	}
	return 0;
}
