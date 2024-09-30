#include <stdio.h>

void copy(char from[], char to[]){
	int I;
	I = 0;
	while((to[I] = from[I]) != '\0')
		++I;
}
