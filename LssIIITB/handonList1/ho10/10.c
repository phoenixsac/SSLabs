/*
============================================================================
Name : 10.c
Author : Sachin Nair
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 
bytes (use lseek) and write again 10 bytes. 
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data. 
Date: 10th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	if(argc!=2)
		printf("Enter filename as argument.");
	char *flname = argv[1];
	int fd=open(flname, O_RDWR);
	if(fd==-1)
		printf("File could not be opened successfully.");
		
	char dtw1[10]="qwertyuiop";

	ssize_t bytesWritten=write(fd,dtw1,sizeof(dtw1));
	
	if(bytesWritten==-1){
		perror("Error in writing to file.");
		close(fd);
		return 1;
	}

	off_t newPos=lseek(fd,10,SEEK_SET);
	
	if(newPos==-1){
		perror("lseek error");
		close(fd);
		return 1;
	}
	
	char dtw2[10]="asdfghjkla";
	
	bytesWritten=write(fd,dtw2,10);
	
	if(bytesWritten==-1){
		perror("Write error.");
		close(fd);
		return 1;
	}

	close(fd);
	printf("File operations completed successfully.");
}

