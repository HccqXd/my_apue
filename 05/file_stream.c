#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
	FILE *file_ptr = fopen("../data/file_stream.txt","a+");
	if(file_ptr==NULL){
		fprintf(stderr,"fopen error\n");
	}

	//下面行读
	char buf[256];
	while(fgets(buf,256,file_ptr) != NULL)
		if(fputs(buf,stdout) == EOF)
			perror("output error");
	if(ferror(file_ptr))
		perror("input error");
	exit(0);
}
