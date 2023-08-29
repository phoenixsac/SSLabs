#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>



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
    lock.l_pid=getpid();

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


	if(get_locking(fd,0)==0){
		printf("\nRead lock acquired successfully.");
		char buff[256];
		ssize_t bytesRead;
		while((bytesRead=read(fd,buff,sizeof(buff)))>0){
			write(STDOUT_FILENO, buff,bytesRead);
		}
		printf("\nReading done.");
		printf("\nPress to unlock.");
		getchar();
		get_locking(fd,2);	
		printf("Read lock released.");
	}
	else{
		printf("\nWaiting...");
	}

	close(fd);
	return 0;
}