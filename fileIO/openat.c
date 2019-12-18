#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<errno.h>

int main(int argc,char* argv[]){

	int fd;
	fd=open("/home/hccqxd/apue/data",O_RDONLY); //打开目录一般是只读打开
	if(fd<0)
                printf("%s\n","open error!");
	int fd1=openat(fd,"1.txt",O_RDWR|O_CREAT|O_TRUNC);  //在路径"/home/hccqxd/apue/data"下打开或者创建文件"1.txt:
	
	if(fd1<0)
		printf("%s\n","open error!");
	exit(0);
}
