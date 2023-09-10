

/*
============================================================================
Name : 8.c
Author : Sachin Nair
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. 
Close the file when end of file is reached.
Date: 10th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	char buffer[1];
	int fd;
	
	if(argc!=2){
		printf("Enter filename to read from");
		return 1;
	}
	
	char *flname=argv[1];
	
	fd = open(flname, O_RDONLY);
	
	if(fd==-1){
		perror("Failed to open file.");
		return 1;
	}	
	
	ssize_t bytesRead;
	char lineBuff[1000];
	int ind=0;
	
	while((bytesRead=read(fd,&buffer,sizeof(buffer)))>0){
		if(buffer[0]=='\n'){
			lineBuff[ind]='\n';
			printf("%s\n",lineBuff);
			sleep(2);
			ind=0;
		}
		else{
			lineBuff[ind]=buffer[0];
			ind++;
		}
	}
	
	close(fd);
	return 0;
}