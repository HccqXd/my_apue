#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[]){
	DIR *dir;
	struct dirent *read_ptr;
	long offset;

	//打开目录
	dir = opendir("../data");

	while((read_ptr = readdir(dir)) != NULL){ //循环读取目录中的目录项
		offset = telldir(dir); //记录当前偏移量
		printf("%ldth file,filename:%s\n",offset,read_ptr->d_name);
	}

	//关闭目录
	closedir(dir);
	return 0;
}
