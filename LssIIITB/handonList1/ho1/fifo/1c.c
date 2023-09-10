/*
============================================================================
Name : 1c.c
Author : Sachin Nair
Description : Create the following types of a files using (i) shell command (ii) system call
 a. soft link (symlink system call)
 b. hard link (link system call)
 c. FIFO (mkfifo Library Function or mknod system call)
Date: 09th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h> 

int main() {
    const char *pipe_name = "myfifo";
    
    if (mkfifo(pipe_name, 0644) == -1) {
        perror("Error creating FIFO");
    } else {
        printf("FIFO created successfully.\n");
    }
    
    return 0;
}
