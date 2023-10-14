/*
============================================================================
Name : 19c.c
Author : Sachin Nair
Description : Create a FIFO file by
    mknod system call
Date: 14th Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(void) {
    //last arg only for char or blk dev
    mknod("fifo", S_IFIFO | 0666, 0);
    return 0;
}