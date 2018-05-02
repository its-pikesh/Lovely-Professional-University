#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	pid_t t;
	t=fork();
	if(t>0)
	{
		printf("Parent has id %d\n",getpid());
		sleep(15);
	}
	else
	{
		printf("Child has id %d\n",getpid());
		exit(0);
	}
}
