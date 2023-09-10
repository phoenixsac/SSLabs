/*
============================================================================
Name : 17.c
Author : Sachin Nair
Description :  7. Write a program to simulate online ticket reservation. Implement write lock 
Write a program to open a file, store a ticket number and exit. Write a separate program, to 
open the file, implement write lock, read the ticket number, increment the number and print 
the new ticket number then close the file.
Date: 10th Sept, 2023.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>



//0 for read, 1 for write and 2 for unlock
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
    return 0;
}



int main(int argc, char *argv[]){

    if(argc!=2){
        printf("Enter filename to store tickets");
        return 1;
    }
    char *filename=argv[1];
    int fd = open(filename,O_RDWR);
    int tkt_num;

    if(fd==-1){
        perror("File could not be opened.");
    }
 
    size_t bytesRead;

    if(get_locking(fd,1)==0){
        bytesRead=read(fd,&tkt_num, sizeof(int));
    }


    tkt_num++;
    if(bytesRead==sizeof(int)){
    	printf("Your ticket no. is : %d",tkt_num);
    }

    lseek(fd,0,SEEK_SET);
    ssize_t bytesWrote = write(fd, &tkt_num, sizeof(int));
    printf("\nPress to unlock.");
    getchar();
    get_locking(fd,2);
    if (bytesWrote == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    close(fd);
}