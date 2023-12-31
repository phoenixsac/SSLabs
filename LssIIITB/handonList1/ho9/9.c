
 
/*
============================================================================
Name : 9.c
Author : Sachin Nair
Description : Write a program to print the following information about a given file.
 a. inode
 b. number of hard links
 c. uid
 d. gid
 e. size
 f. block size
 g. number of blocks
 h. time of last access
 i. time of last modification
 j. time of last change
Date: 10th Sept, 2023.
============================================================================
*/



#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
	char fpath[]="samplefile";
	struct stat fileInfo;
	
	if(stat(fpath,&fileInfo)==0){
		printf("Inode is : %lu\n",fileInfo.st_ino);
		printf("No. of hard links is : %lu\n",fileInfo.st_nlink);
		printf("UID : %u\n",fileInfo.st_uid);
		printf("GID is : %u\n",fileInfo.st_gid);
		printf("Size is : %ld\n",fileInfo.st_size);
		printf("Blocks is : %ld\n",fileInfo.st_blocks);
		printf("Block size is : %ld\n",fileInfo.st_blksize);
		printf("Time of last access : %ld\n",fileInfo.st_atime);
		printf("Time of last modification : %ld\n",fileInfo.st_mtime);
		printf("Time of last change : %ld\n",fileInfo.st_ctime);
	}
}
