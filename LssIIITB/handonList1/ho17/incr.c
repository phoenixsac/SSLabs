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
    //if lock is unreleased and file /process closes abruptly, OS auto releases the lock
    lock.l_pid=getpid();

    //error not in case of already existing file lock, due to some other error maybe
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

    if(fcntl(fd,F_SETLK, &lock)==-1){
    	perror("Error releasing write lock");
    }

}



int main(int argc, char *argv[]){

    if(argc!=2){
        printf("Enter filename to store tickets");
        return 1;
    }
    char *filename=argv[1];
    int fd = open(filename,O_RDWR);

    if(fd==-1){
        perror("File could not be opened.");
    }
   

    char buff[256];

    if(get_write_lk(fd)==0){
        ssize_t bytesRead=read(fd,buff, sizeof(buff));
        buff[bytesRead]='\0';
    }

    int tkt_num=atoi(buff);

    tkt_num++;
    printf("Your ticket no. is : %d",tkt_num);

    snprintf(buff,sizeof(buff),"%d",tkt_num);
    lseek(fd,0,SEEK_SET);
    ssize_t bytesWrote = write(fd, buff, sizeof(buff));
    printf("\nPress to unlock.");
    getchar();
    rel_write_lk(fd);
    if (bytesWrote == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    close(fd);
}