/*
============================================================================
Name : 1b.c
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
int main(){
	const char* targetfile="samplefile";
	const char* link_type="hardlink";
	if(link(targetfile,link_type)==-1){
		perror("Some error occured");
		return 1;
		}
	return 0;
}
