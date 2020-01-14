#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[]){
	if(link("../data/tmpfile","../data/tmpfile_link") < 0){
                perror("link error");
                exit(1);
        }

	if(unlink("../data/tmpfile") < 0){
		perror("unlink error");
		exit(1);
	}

	printf("file unlinked\n");
	exit(0);
}
