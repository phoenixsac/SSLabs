
/*
============================================================================
Name : 6.c
Author : Sachin Nair
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls 
Date: 10th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main(){
	char buffer[1024];
	ssize_t bytes;
	while((bytes=read(STDIN_FILENO, buffer, sizeof(buffer)))>0){
		write(STDOUT_FILENO, buffer, bytes);
	}
	return 0;
}
