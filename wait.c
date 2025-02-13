#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	pid_t cpid,pid;
	pid=fork();
	if(pid==0)
	{
		exit(0);
	}
	else
	{
		cpid=wait(NULL);
		printf("Parent process ID : %d\n",getpid());
		printf("Child process ID : %d\n",cpid);
	}
}