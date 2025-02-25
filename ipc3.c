#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(){
	void *shared_memory;
	int shmid;

	shmid = shmget((key_t)2345, 1024, 0666);
	if (shmid == -1) {
		perror("shmget failed");
		exit(1);
	}

	shared_memory = shmat(shmid, NULL, 0);
	if (shared_memory == (void *)-1) {
		perror("shmat failed");
		exit(1);
	}
	printf("Process attached at %p\n", shared_memory);
	printf("Data read from shared memory: %s\n", (char *)shared_memory);
	return 0;
}
