/*
============================================================================
Name : 21a.c
Author : Sachin Nair
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 14th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

//sequence matters else will be blocked and deadlock can happen
int main(void) {
    int buff[80];
    int fd1 = open("fifo", O_WRONLY);

    printf("Enter the text: ");
    scanf("%[^\n]", buff);
    write(fd1, buff, sizeof(buff));

    int fd2 = open("fifo2", O_RDONLY);
    read(fd2, buff, sizeof(buff));
    printf("The text: %s\n", buff);
    
    return 0;
}