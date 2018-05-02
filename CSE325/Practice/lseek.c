//wap using system calls whill will read from 10th character to 25 th character from a file opened in read only mode

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
	int fd,n;
	char buff[15];
	fd=open("file1",O_RDONLY);
	lseek(fd,0,SEEK_SET);
	lseek(fd,9,SEEK_CUR);
	n=read(fd,buff,15);
	write(1,buff,n);
	fflush(stdout);
	printf("\n");
	close(fd);
}
