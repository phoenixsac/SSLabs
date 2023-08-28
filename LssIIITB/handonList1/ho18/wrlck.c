#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define SLEEP_TIMEOUT 2
#define RECORD_SIZE 5

int get_write_lk(int fd,int recordno){
	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start = (recordno-1)*RECORD_SIZE;
    lock.l_len = RECORD_SIZE;

    if(fcntl(fd,F_SETLKW,&lock)==-1){
    	perror("\nError getting write lock");
    	return -1;
    }
    else{
    	printf("\nWrite lock successfully acquired on record no. %d.",recordno);
    }
    return 0;
}

int rel_write_lk(int fd,int recordno){
	struct flock lock;
	lock.l_type=F_UNLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start = (recordno-1)*RECORD_SIZE;
    lock.l_len = RECORD_SIZE;

    if(fcntl(fd,F_SETLK, &lock)==-1){
    	perror("\nError releasing write lock");
    }
    else{
    	printf("\nWrite lock on record %d released.",recordno);
    }

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

	if(get_write_lk(fd,recordno)==0){
		//char recordData[]="\n";
		lseek(fd,(recordno-1)*RECORD_SIZE,SEEK_SET);
		//write(fd,recordData,sizeof(recordData)-1);

		printf("\nData writing done.");
		printf("\nPress to unlock");
		getchar();
		rel_write_lk(fd,recordno);
		
	}
	else{
		printf("\nWaiting to write..");
	}

	close(fd);
	return 0;
}