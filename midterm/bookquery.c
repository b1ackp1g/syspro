#include <stdio.h>
#include "bookquery.h"

int main(int argc, char *argv[]){
	FILE *fp;
	int input;
	struct bookquery book;
	if(argc != 2){
		fprintf(stderr, "How to use: %s File Name\n", argv[0]);
		return 1;
	}
	if((fp=fopen(argv[1], "rb")) == NULL){
		fprintf(stderr, "Error Open File\n");
		return 2;
	}
	printf("--bookquery--\n");
	while(1){
		printf("0: list of all books, 1: list of available books ) ");
		scanf("%d", &input);
		printf("%4s %10s %10s %6s %12s %6s\n", "id", "bookname", "author", "year", "numofborroe", "borrow");
		while(fread(&book, sizeof(book), 1, fp) > 0){
			if(input == 0){
				printf("%4d %10s %10s %6d %12d", book.id, book.bookname, book.author, book.year, book.numofborrow);
				if(book.borrow == 1)
					printf(" %5s\n", "False");
				else if(book.borrow == 0)
					printf(" %5s\n", "True");
			}
			if(input == 1){
				if(book.borrow == 1)
					printf("%4d %10s %10s %6d %12d %5s\n", book.id, book.bookname, book.author, book.year, book.numofborrow, "True");
			}
		}
		return 0;
	}
	return 0;
}
