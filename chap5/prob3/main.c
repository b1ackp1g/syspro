#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	int fd1, fd2, n;
	char buff[BUFSIZE];
	if(argc != 3){
		fprintf(stderr,"How to use: %s file1 file2\n", argv[0]);
		close(fd1);
		close(fd2);
		exit(1);
	}
	if((fd1 = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		close(fd1);
		close(fd2);
		exit(2);
	}
	if((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600)) == -1){
		perror(argv[2]);
		close(fd1);
		close(fd2);
		exit(3);
	}
	while((n = read(fd1, buff, BUFSIZE)) > 0)
		write(fd2, buff, n);
	close(fd1);
	close(fd2);
	exit(0);
}
