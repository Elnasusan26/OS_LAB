#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	char file[100];
	struct stat *sfile;
	sfile=(struct stat*)malloc(sizeof(struct stat));
	printf("Enter the file path\n");
	scanf("%s",file);
	stat(file,sfile);
	printf("st mode =%o\n",sfile->st_mode);
	printf("size id =%ld\n",sfile->st_blksize);
	printf("file last accessed is %ld\n",sfile->st_atime);
	printf("file last modified is %ld\n",sfile->st_mtime);
	printf("User id is %d\n",sfile->st_uid);
	printf("no.of links is %d\n",sfile->st_nlink);
}