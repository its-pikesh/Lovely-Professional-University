//WAP to create two threads. One will print the fibonacci series and the other thread will find factorial of a number entered by the user.

#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<pthread.h>

int fact = 1;

void *fibo(void *number)
{
	int n=atoi(number);
	int n1=0,n2=1,next;
	printf("Fibonacci Series for %d\n",n);
	for(int i=1;i<=n;++i)
	{
		printf("%d ",n1);
		next=n1+n2;
		n1=n2;
		n2=next;
	}
	printf("\n");
	pthread_exit("Fibonacci thread finished");
}

void *factorial(void *number)
{
	int n=atoi(number);
	for(int i=1;i<=n;++i)
	{
		fact*=i;
	}
	printf("Factorial of %d is %d\n",n,fact);
	pthread_exit("Factorial thread finished");
}

int main()
{
	int n;
	char *buff[10];
	void *result;
	pthread_t fib_thread,fact_thread;
  
	printf("Enter a number: ");
	n=read(0,buff,50);
  
	pthread_create(&fib_thread,NULL,fibo,(void *)buff);
	pthread_join(fib_thread,&result);
	pthread_create(&fact_thread,NULL,factorial,(void *)buff);
	pthread_join(fact_thread,&result);
  
	exit(EXIT_SUCCESS);
}
