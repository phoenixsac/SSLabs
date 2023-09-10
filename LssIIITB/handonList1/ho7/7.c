
/*
============================================================================
Name : 7.c
Author : Sachin Nair
Description :  Write a program to copy file1 into file2 ($cp file1 file2)
Date: 10th Sept, 2023.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main(){
	int srcfd,destfd;
	char buffer[1024];
	ssize_t bytesRead, bytesWrote;
	
	srcfd=open("inputfile.txt",O_RDONLY);
	
	if(srcfd==-1){
		printf("Error opening inout file.");
		return 1;
	}
	
	destfd=open("targetfile.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if(destfd==-1){
		printf("Error opening target file.");
		return 1;
	}
	
	while((bytesRead=read(srcfd, buffer, sizeof(buffer)))>0){
		bytesWrote=write(destfd, buffer, bytesRead);
		if(bytesWrote==-1){
			close(srcfd);
			close(destfd);
			return 1;
		}
	}
	
	close(srcfd);
	close(destfd);
	
	printf("Data copied successfully from inputfile to target file.");
	return 0;
	
	
}
