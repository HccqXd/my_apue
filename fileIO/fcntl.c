#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc,char* argv[]){
	int fd,val;
	if(fd = open("../data/1.txt",O_RDONLY)<0) //以只读方式打开一个文件
	       printf("open or create file error!");
	if((val=fcntl(fd,F_GETFL,0))<0)
		printf("fcntl error for fd %d",fd);
	switch (val & O_ACCMODE) //宏O_ACCMODE作为一个掩码与文件状态作AND位运算，产生一个表示文件访问模式的值
	{	
		case O_RDONLY:	
			printf("read only");
			break;
		case O_WRONLY:
			printf("write only");
			break;
		case O_RDWR:
			printf("read write");
			break;
		default:
			printf("unknown access mode");
			break;
	}
	if(val & O_APPEND)
		printf(",append");
	if(val & O_NONBLOCK)
		printf(",nonbloking");
	if(val & O_SYNC)
		printf(",synchronous writes");
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
	if(val & O_FSYNC)
		printf(",synchronous writes");
#endif
	putchar('\n');

	//下面修改文件权限为O_RDWR|O_NONBLOCK
	int flags=O_NONBLOCK;
	val|=flags;
	if(fcntl(fd,F_SETFL,val)<0) //更改文件访问权限为O_RDONLY|O_NONBLOCK
		printf("fcntl error for fd %d",fd);
	if((val=fcntl(fd,F_GETFL,0))<0)
                printf("fcntl error for fd %d",fd);

	switch (val & O_ACCMODE) //宏O_ACCMODE作为一个掩码与文件状态作AND位运算，产生一个表示文件访问模式的值
        {
                case O_RDONLY:
                        printf("read only");
                        break;
                case O_WRONLY:
                        printf("write only");
                        break;
                case O_RDWR:
                        printf("read write");
                        break;
                default:
                        printf("unknown access mode");
                        break;
        }

        if(val & O_APPEND)
                printf(",append");
	if(val & O_SYNC)
                printf(",synchronous writes");
	if(val & O_NONBLOCK)
		printf(",nonblocking");
	putchar('\n');
	close(fd);
	exit(0);
}
