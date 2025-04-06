#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("exec starts\n");
		execl("/bin/ls","ls","-1",NULL);
		printf("exec didn't work\n");
	}
	else
	{
		wait(0);
		printf("parent ls is completed in child\n");
	}
	return 0;
}