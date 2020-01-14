#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[]){
	if(link("../data/tmpfile","../data/tmpfile_link") < 0){
		perror("link error");
		exit(1);
	}
	printf("file linked\n");
	exit(0);
}
