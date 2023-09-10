/*
============================================================================
Name : 24.c
Author : Sachin Nair
Description :   Write a program to create an orphan process.
============================================================================
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	if(fork()==0){
		printf("In child. Before being an orphan, ParentID : %d\n",getppid());
		sleep(30);
		printf("In child. After being an orphan, ParentID : %d\n",getppid());
	}
	else{
		printf("In parent. Id : %d\n",getpid());
		sleep(5);
		exit(0);
	}
}