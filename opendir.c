#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
struct dirent *dptr;
int main(int argc,char *argv[])
{
	char buff[256];
	DIR *dirp;
	printf("enter directory name\n");
	scanf("%s", buff);
	dirp=opendir(buff);
	if(dirp==NULL)
	{
		printf("ERROR");
		exit(1);
	}
	while(dptr=readdir(dirp))
	{
		printf("%s",dptr->d_name);
	}
	closedir(dirp);
}