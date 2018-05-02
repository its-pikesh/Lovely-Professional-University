#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>

int main()
{
	int fd,n;
	char file1[100],file2[100],buff[100];
	printf("Enter the name of file to copy content from: ");
	scanf("%s",file1);
	fd=open(file1,O_RDONLY);
	if(fd == -1)
	{
		printf("Error opening file try again.\n");
		exit(EXIT_FAILURE);
	}
	n=read(fd,buff,100);
	close(fd);
	printf("Enter the name of file to copy content to: ");
	scanf("%s",file2);
	fd=open(file2,O_CREAT|O_WRONLY);
	if(fd == -1)
	{
		printf("Error opening file try again.\n");
		exit(EXIT_FAILURE);
	}
	write(fd,buff,n);
	close(fd);
	printf("Data successfully copied from %s to %s\n",file1,file2);
}
