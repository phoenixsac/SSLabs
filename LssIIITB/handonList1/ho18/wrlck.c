/*
============================================================================
Name : 18.c
Author : Sachin Nair
Description :   Write a program to perform Record locking.
 a. Implement write lock
 b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access 
to avoid race condition.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define SLEEP_TIMEOUT 2
#define RECORD_SIZE 5



//0 for read, 1 for write and 2 for unlock
int get_locking(int fd, int recordno, int l_type){
    struct flock lock;
    if(l_type==0)
        lock.l_type=F_RDLCK;
    else if(l_type==2)
        lock.l_type=F_UNLCK;
    else if(l_type==1)
        lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start = RECORD_SIZE*(recordno-1);;
    lock.l_len = RECORD_SIZE;
    lock.l_pid=getpid();

    if(fcntl(fd,F_SETLKW, &lock)==-1){
        perror("Error locking or releasing lock...");
        return -1;
    }
    return 0;
}




int main(int argc, char *argv[]){

	if(argc!=3)
		printf("\nFilename or record no. should be entered as a argument.");
	char *filename=argv[1];
	int fd=open(filename,O_RDWR|O_CREAT|O_APPEND,0644);

	char buff[RECORD_SIZE];
	int recordno=atoi(argv[2]);


	if(fd==-1){
		perror("\nError opening file.");
		return 1;
	}

	if(get_locking(fd,recordno,1)==0){
		
		lseek(fd,(recordno-1)*RECORD_SIZE,SEEK_SET);
		printf("\nData writing done.");
		printf("\nPress to unlock");
		getchar();
		get_locking(fd,recordno,2);
		
	}
	else{
		printf("\nWaiting to write..");
	}

	close(fd);
	return 0;
}