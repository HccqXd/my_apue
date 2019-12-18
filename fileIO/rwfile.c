#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
	int fd1,fd2,n;
	char buf[6];
	fd1=open("/home/hccqxd/apue/data/1.txt",O_RDWR);
	if(fd1<0)
		printf("open error!");

	fd2=open("/home/hccqxd/apue/data/2.txt",O_RDWR);
        if(fd2<0)
                printf("open error!");

	lseek(fd1,6,SEEK_CUR); //将文件1的偏移量移至距开始第6个字符，也就是“w”位置
	read(fd1,buf,5);	//将world读至buf中
	write(fd2,buf,5);	//将buf中的world写入文件2

	close(fd1);
	close(fd2);
	
	exit(0);
}
