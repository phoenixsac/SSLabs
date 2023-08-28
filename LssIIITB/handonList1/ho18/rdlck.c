#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define SLEEP_TIMEOUT 2
#define RECORD_SIZE 5

int get_read_lk(int fd,int recordno){
	struct flock lock;
	lock.l_type=F_RDLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start = RECORD_SIZE*(recordno-1);
    lock.l_len = RECORD_SIZE;

    if(fcntl(fd,F_SETLKW,&lock)==-1){
    	perror("\nError getting read lock");
    	return -1;
    }
     else{
    	printf("\nRead lock acquired on record %d.",recordno);
    }
    return 0;
}


int rel_read_lk(int fd,int recordno){
	struct flock lock;
	lock.l_type=F_UNLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start = RECORD_SIZE*(recordno-1);
    lock.l_len = RECORD_SIZE;

    if(fcntl(fd,F_SETLK, &lock)==-1){
    	perror("\nError releasing read lock");
    }
     else{
    	printf("\nRead lock on record %d released.",recordno);
    }
}

int main(int argc, char *argv[]){

	if(argc!=3)
		printf("\nFilename and record no. should be entered as a argument.");

	char *filename=argv[1];
	int fd=open(filename,O_RDONLY);
	int recordno=atoi(argv[2]);

	if(fd==-1){
		perror("\nError opening file.");
		return 1;
	}

	if(get_read_lk(fd,recordno)==0){

		char buff[RECORD_SIZE];
		ssize_t bytesRead;
		lseek(fd,(recordno-1) * RECORD_SIZE,SEEK_SET);

		bytesRead=read(fd,buff, sizeof(buff));
		buff[bytesRead] = '\n';
		write(STDOUT_FILENO,buff,bytesRead);
		printf("\nReading done.");

		printf("\nPress enter to unlock...");
		getchar();
		rel_read_lk(fd,recordno);
	}


	close(fd);
	return 0;
}