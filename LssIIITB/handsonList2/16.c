/*
============================================================================
Name : 16.c
Author : Sachin Nair
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 14th Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<string.h>

//fd1 from parent to child
//fd2 from child to parent
int main(void) {
    int fd1[2], fd2[2], count;
    char buff[80];
    pipe(fd1);
    pipe(fd2);
    if(fork()) {
        char* msg = "Message from parent.\n";
        close(fd1[0]);
        write(fd1[1], msg, strlen(msg));
        
        close(fd2[1]);
        count = read(fd2[0], buff, sizeof(buff));
        write(STDOUT_FILENO, buff, count);
    } else {
        char* msg = "Message from child.\n";
        close(fd1[1]);
        //blocking, waits until parent also writes
        count = read(fd1[0], buff, sizeof(buff));
        write(STDOUT_FILENO, buff, count);
        
        close(fd2[0]);
        write(fd2[1], msg, strlen(msg));
    }

    return 0;
}