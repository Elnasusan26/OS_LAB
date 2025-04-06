#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main()
{
	pid_t child_pid;
	child_pid=fork();
	if(child_pid<0)
	{
		printf("FORK FAILED");
	}
	else if(child_pid==0)
	{
		printf("Child process successfully created!\n");
		printf("child_pid=%d | parent_pid=%d\n",getpid(),getppid());
	}
	else
	{
		wait(NULL);
		printf("Parent process successfully created!\n");
		printf("child_pid=%d | parent_pid=%d\n",getpid(),getppid());
	}
	return 0;
}
