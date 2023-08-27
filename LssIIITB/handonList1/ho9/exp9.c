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
