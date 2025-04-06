#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
	int pid,pid1,pid2;
	pid=fork();
	if(pid==-1)
	{
		printf("ERROR");
		exit(1);
	}
	if(pid!=0)
	{
		pid1=getpid();
		printf("Process ID of parent: %d\n",pid1);
	}
	else
	{
		pid2=getpid();
		printf("Process ID of child: %d\n",pid2);
	}
}
