#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define SLEEP_TIMEOUT 2
#define RECORD_SIZE 256

int get_write_lk(int fd,int recordno){
	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start = recordno*RECORD_SIZE;
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
	lock.l_start = recordno*RECORD_SIZE;
    lock.l_len = RECORD_SIZE;

    if(fcntl(fd,F_SETLK, &lock)==-1){
    	perror("\nError releasing write lock");
    }
    else{
    	printf("\nWrite lock on record %d released.",recordno);
    }

}

int get_read_lk(int fd,int recordno){
	struct flock lock;
	lock.l_type=F_RDLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start = RECORD_SIZE*recordno;
    lock.l_len = RECORD_SIZE;

    if(fcntl(fd,F_SETLKW,&lock)==-1){
    	perror("\nErroR getting read lock");
    	return -1;
    }
     else{
    	printf("\nRead lock successfully acquired on record %d.",recordno);
    }
    return 0;
}


int rel_read_lk(int fd,int recordno){
	struct flock lock;
	lock.l_type=F_UNLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start = RECORD_SIZE*recordno;
    lock.l_len = RECORD_SIZE;

    if(fcntl(fd,F_SETLK, &lock)==-1){
    	perror("\nError releasing read lock");
    }
     else{
    	printf("\nRead lock on record %d released.",recordno);
    }
}

int main(int argc, char *argv[]){

	if(argc!=2)
		printf("\nFilename should be entered as a argument.");
	char *filename=argv[1];
	int fd=open(filename,O_RDWR|O_CREAT|O_APPEND,0644);

	char buff[RECORD_SIZE];
	int recordno=5;
	memset(buff, 0, sizeof(buff));

	if(fd==-1){
		perror("\nError opening file.");
		return 1;
	}

	if(get_write_lk(fd,recordno)==0){
		char *recordData="6,bfDD7CDEF5D865B,Erin,Day,Male,tconner@example.org,Waste management officer\n";
		lseek(fd,recordno*RECORD_SIZE,SEEK_SET);
		write(fd,recordData,RECORD_SIZE);
		sleep(SLEEP_TIMEOUT);
		printf("\nData writing done.");
		rel_write_lk(fd,recordno);
		
	}
	else{
		printf("\nWaiting to write..");
	}


	//recordno=5;

	if(get_read_lk(fd,recordno)==0){

		char buff[256];
		ssize_t bytesRead;
		lseek(fd,recordno*RECORD_SIZE,SEEK_SET);
		while((bytesRead=read(fd,buff,RECORD_SIZE))>0){
			write(STDOUT_FILENO, buff,bytesRead);
		}
		printf("\nReading done.");
		sleep(SLEEP_TIMEOUT);
		rel_read_lk(fd,recordno);
		
	}
	else{
		printf("\nWaiting to read...");
	}

	close(fd);
	return 0;
}