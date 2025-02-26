#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
	int pid,pid1,pid2;
	pid = fork();
	
	if(pid == -1){
		printf("Error in process");
		exit(1);
	}
	
	if(pid != 0){
		pid = getpid();
		printf("Process id of Parent = %d\n", pid1);
	}else{
		pid2 = getpid();
		printf("Process id of child %d\n", pid2);
	}
}
