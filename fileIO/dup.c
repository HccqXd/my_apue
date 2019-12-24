#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
	int fd;
	char buf[6];
	fd=open("../data/1.txt",O_RDWR|O_APPEND); //以追加方式打开
	if(fd<0)
		printf("open error!");
	int fd_dup=dup(fd);
	read(STDIN_FILENO,buf,5); //从标准输入写5个字节的数据到buf中
	write(fd_dup,buf,5); //将buf中的数据写入1.txt末尾

	close(fd);
	close(fd_dup);

	exit(0);
}
