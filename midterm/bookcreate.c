#include <stdio.h>
#include "bookquery.h"

int main(int argc, char *argv[0]){
	struct bookquery book;
	FILE *fp;
	char br[6];
	if(argc!=2){
		fprintf(stderr, "How to use %s FileName\n", argv[0]);
		return(1);
	}
	fp = fopen(argv[1], "wb");
	printf("%4s %10s %10s %6s %12s %6s\n", "id", "bookname", "author", "year", "numofborrow", "borrow");
	while (scanf("%4d %10s %10s %6d %12d %5s", &book.id, book.bookname, book.author, &book.year, &book.numofborrow, br) == 6){
		if(strcmp(br, "False"))
			book.borrow = 0;
		else if(strcmp(br, "True"))
			book.borrow = 1;
		else{
			fprintf(stderr, "How to use %s FileName\n", argv[0]);
			return(2);
		}
		fwrite(&book, sizeof(book), 1, fp);
	}
	fclose(fp);
	return(0);
}
