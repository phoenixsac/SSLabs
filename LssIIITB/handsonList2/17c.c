/*
============================================================================
Name : 17c.c
Author : Sachin Nair
Description : Write a program to execute ls -l | wc.
    a. use fcntl
Date: 14th Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>

//fcntl checks and assigns fd incrementally if not available
int main(void) {
    int fd[2];
    pipe(fd);
    if(fork()) {
        close(STDOUT_FILENO);
        close(fd[0]);
        fcntl(fd[1], F_DUPFD, STDOUT_FILENO);
        execl("/bin/ls", "ls", "-l", NULL);
    } else {
        close(STDIN_FILENO);
        close(fd[1]);
        fcntl(fd[0], F_DUPFD, STDIN_FILENO);
        execlp("wc", "wc", NULL);
    }

    return 0;
}