#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<errno.h>

#define RW S_IRUSR|S_IWUSR //S_IRUSR:用户读权限

int main(int argc,char* argv[]){
	int fd;
	fd = open("1.txt",O_RDWR|O_CREAT|O_TRUNC,RW); //O_CREAT可选常量之一，表明若此文件不存在则创建它
							//使用此常量必须要指定第三个参数，这里指定用户读写权限
							//O_TRUNC：可选常量之一，如果次文件存在，而且为只写或读-写成功打开，则将其长度截断为0
	if(fd<0)
		printf("%s\n","open error!");
	exit(0);
}

