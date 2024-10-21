#include <stdio.h>

int main(int argc, char *argv[])
{
	int c;
	FILE *fp1, *fp2;
	if(argc != 4){
		fprintf(stderr, "How to use1: %s File1 File2\n", argv[0]);
		return 1;
	}
   	fp1 = fopen(argv[2], "r");
   	if(fp1 == NULL){
	   	fprintf(stderr, "File %s Open Error\n", argv[1]);
	   	return 2;
   	}

   	fp2 = fopen(argv[3], "w");
   	while ((c = fgetc(fp1)) != EOF){
		if(*argv[1] == '0'){}
		else if(*argv[1] == '1'){
			if('A'<=c&&c<='Z')
				c=c+32;
		}else if(*argv[1] == '2'){
			if('a'<=c&&c<='z')
				c=c-32;
		}else{
			fprintf(stderr, "How to use2: %s File1 File2\n", argv[0]);
			return 3;
		}
	   	fputc(c, fp2);
	}
   	fclose(fp1);
   	fclose(fp2);
   	return 0;
}
