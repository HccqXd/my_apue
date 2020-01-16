#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	FILE *file_ptr = freopen("../data/file_stream.txt","w",stdout);
	if(file_ptr==NULL){
		fprintf(stderr,"error redirecting stdout\n");
	}
	for(int i = 0;i < 10;i++)
		printf("%d",i);
	printf("\n");
	fclose(stdout);
	return 0;
}
