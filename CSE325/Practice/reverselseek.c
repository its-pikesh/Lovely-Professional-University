//Reverse lseek()

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>

int main()
{
	int fd,i=0;
	char buff;
	fd=open("file2.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("Error opening the file");
		exit(EXIT_FAILURE);
	}
	lseek(fd,-1,SEEK_END);
	do
	{
		read(fd,&buff,1);
		printf("%c",buff);
		i++;
	}while(lseek(fd,-1-(i),SEEK_END)!=-1);
	printf("\n");
}
