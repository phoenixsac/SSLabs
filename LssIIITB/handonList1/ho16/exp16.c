#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define SLEEP_TIMEOUT 5

int get_write_lk(int fd){
	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start = 0;
    lock.l_len = 0;

    if(fcntl(fd,F_SETLKW,&lock)==-1){
    	perror("Error getting write lock");
    	return -1;
    }
    return 0;
}

int rel_write_lk(int fd){
	struct flock lock;
	lock.l_type=F_UNLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start = 0;
    lock.l_len = 0;

    if(fcntl(fd,F_SETLKW, &lock)==-1){
    	perror("Error releasing write lock");
    }

}

/*int get_read_lk(int fd){
	struct flock lock;
	lock.l_type=F_RDLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start = 0;
    lock.l_len = 0;

    if(fcntl(fd,F_SETLKW,&lock)==-1){
    	perror("ErroR getting read lock");
    	return -1;
    }
    return 0;
}*/


/*int rel_read_lk(int fd){
	struct flock lock;
	lock.l_type=F_UNLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start = 0;
    lock.l_len = 0;

    if(fcntl(fd,F_SETLKW, &lock)==-1){
    	perror("Error releasing read lock");
    }
}*/
//0 for read, 1 for write, 2 for unlock 
int get_locking(int fd, int l_type){
	struct flock lock;
	if(l_type==0)
		lock.l_type=F_RDLCK;
	else if(l_type==2)
		lock.l_type=F_UNLCK;
	else if(l_type==1)
		lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start = 0;
    lock.l_len = 0;

    if(fcntl(fd,F_SETLKW, &lock)==-1){
    	perror("Error locking or releasing lock...");
    	return -1;
    }
  
}

int main(int argc, char *argv[]){

	if(argc!=2)
		printf("Filename should be entered as a argument.");
	char *filename=argv[1];
	int fd=open(filename,O_RDWR|O_CREAT|O_APPEND,0644);

	if(fd==-1){
		perror("Error opening file.");
		return 1;
	}

	if(get_locking(fd,1)==0){
		printf("\nWrite lock successfully acquired. Writing data...");
		char *data="Writing data after acquiring write lock.\n";
		sleep(SLEEP_TIMEOUT);
		write(fd,data,strlen(data));
		printf("\nData writing done.");
		printf("Press to unlock.");
		getchar();
		get_locking(fd,2);
		printf("Write lock released.");
	}
	else{
		printf("\nWaiting...");
	}

	if(get_locking(fd,0)==0){
		printf("\nRead lock acquired successfully.");
		char buff[256];
		ssize_t bytesRead;
		while((bytesRead=read(fd,buff,sizeof(buff)))>0){
			write(STDOUT_FILENO, buff,bytesRead);
		}
		printf("\nReading done.");
		printf("Press to unlock.");
		getchar();
		get_locking(fd,0);	
		printf("Read lock released.");
	}
	else{
		printf("\nWaiting...");
	}

	close(fd);
	return 0;
}