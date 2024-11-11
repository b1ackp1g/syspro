#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
int main(int argc, char* argv[]){
	if(argc<2){
		fprintf(stderr,"Usage : %s -option \n", argv[0]);
		exit(1);
	}
	if(strcmp(argv[1], "-e")==0){
		if(argc>2){
			char *ptr = getenv(argv[2]);
			if(ptr != NULL){
				printf("%s = %s \n", argv[2], ptr);
			}else{
				printf("Environment variable %s not found\n", argv[2]);
			}
		}else{
			char ** ptr;
			extern char ** environ;
			for(ptr=environ;*ptr!=0;ptr++)
				printf("%s \n", *ptr);
		}
	}else if(strcmp(argv[1], "-u")==0){
		printf("My Realistic User ID : %d(%s) \n", getuid(), getpwuid(getuid())->pw_name);
		printf("My Valid User ID : %d(%s) \n", geteuid(), getpwuid(geteuid())->pw_name);
	}else if(strcmp(argv[1], "-g")==0){
		printf("My Realistic Group ID : %d(%s) \n", getgid(), getgrgid(getgid())->gr_name);
		printf("My Valid Group ID : %d(%s) \n", getegid(), getgrgid(getegid())->gr_name);
	}else if(strcmp(argv[1], "-i")==0){
		printf("My Process Number : [%d] \n", getpid());
	}else if(strcmp(argv[1], "-p")==0){
		printf("My Parent's Process Number : [%d] \n", getppid());
	}else{
		fprintf(stderr,"Invalid option\n");
	}
	exit(0);
}
