/*
============================================================================
Name : 17.c
Author : Sachin Nair
Description :  Write a program to simulate online ticket reservation. Implement write lock 
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


int main(int argc, char *argv[]){

    if(argc!=2){
        printf("Enter filename to store tickets");
    }
    char *filename=argv[1];
    int fd = open(filename,O_RDWR|O_TRUNC);

    if(fd==-1){
        perror("File could not be opened.");
    }
    int tktInit=2000;
    char buff[256];
    snprintf(buff, sizeof(buff), "%d", tktInit);
    
    ssize_t bytesWrote = write(fd, buff, strlen(buff));
    if (bytesWrote == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    close(fd);
}