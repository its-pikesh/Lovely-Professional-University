//wap to create a file1.txt in which write last 10 characters which is read from file2.txt. Also print the total size of file file2.txt and last ten value

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>

int main()
{
	int fd,n,size=0;
	char buff[100],sizebuff[100 ];
	fd=open("file2.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("Error opening file2.txt.");
		exit(EXIT_FAILURE);
	}
	//calculate size
	while ((n=read(fd, sizebuff, sizeof(sizebuff))) > 0)
	{
		size += n;
	}
	//icha anusaar -11 ya -10 use kro
	lseek(fd,-11,SEEK_END);
	n=read(fd,buff,10);
	close(fd);
	fd=open("file1.txt",O_CREAT|O_TRUNC|O_WRONLY, 0777);
	write(fd,buff,n);
	close(fd);
	printf("Data written to file1.txt\n");
	printf("Size of file2.txt: %d bytes\n",size);
	printf("Last 10 characters of file2.txt: %s\n",buff);
}
