/*
============================================================================
Name : 22.c
Author : Sachin Nair
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char*argv[]){
	int fd=open(argv[1],O_CREAT|O_WRONLY|O_TRUNC);
	if(fd==-1){
		printf("Error creating file.\n");
	}

	int par_pid=getpid();
	int child_pid=fork();

	if(child_pid==-1){
		printf("Error forking.");
	}
	else if(child_pid==0){
		char ch_buff[256]="This is text written by child process!\n";
		write(fd,ch_buff,sizeof(ch_buff));
		close(fd);
		exit(0);
	}
	else{
		char par_buff[256]="This is text written by parent process!\n";
		write(fd,par_buff,sizeof(par_buff));
		close(fd);
	}
	return 0;
}
