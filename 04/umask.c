#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(int argc,char *argv[]){
	umask(0); //不屏蔽任何访问权限
	if(creat("foo",RWRWRW)<0) //创建具有用户读写，组读写，其他读写权限的文件
		printf("create error for foo\n");
	umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);//屏蔽组读写，其他读写权限
	if(creat("bar",RWRWRW)<0) //此次创建的文件只有用户读写权限
		printf("create error for bar\n");
	exit(0);
}
