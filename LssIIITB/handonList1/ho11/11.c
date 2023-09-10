
/*
============================================================================
Name : 11.c
Author : Sachin Nair
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the 
descriptors and check whether the file is updated properly or not.
 a. use dup
 b. use dup2
 c. use fcntl
Date: 10th Sept, 2023.
============================================================================
*/

#include <unistd.h> 
#include <fcntl.h>  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int srcfd,dupfd;

	srcfd=open("samplefile.txt", O_WRONLY | O_APPEND);	
	if(srcfd==-1){
		printf("Error opening inout file.");
		return 1;
	}
	else{
		dupfd=dup(srcfd);
	}
	printf("%d\n",srcfd);
	printf("%d",dupfd);
	
	char fd1Str[10],fd2Str[10];
	sprintf(fd1Str,"%d",srcfd);
	sprintf(fd2Str,"%d",dupfd);
	
	write(srcfd, fd1Str, strlen(fd1Str));
	write(dupfd, fd2Str, strlen(fd2Str));
	
	close(srcfd);
	close(dupfd);
}