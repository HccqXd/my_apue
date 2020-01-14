#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char** argv[]){
	struct stat buf;
	if(stat("../data/1.txt",&buf)<0){
		printf("stat error!\n");
		return -1;
	}
	if(S_ISREG(buf.st_mode)) //检查是不是普通文件
		printf("regular file!\n");
	printf("file type:%u ",buf.st_mode);
	printf("i-node number:%ld ",buf.st_ino);
	printf("user ID of owner:%u ",buf.st_uid);
	printf("size:%ld\n",buf.st_size);
	return 0;
}
