/*
============================================================================
Name : 23.c
Author : Sachin Nair
Description :  Write a program to create a Zombie state of the running program.
============================================================================
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>


int main(){
	if(fork()==0){
		printf("In child. PID - %d\n",getpid());
	}
	else{
		printf("In parent. Id : %d\n",getpid());
		sleep(100);
		wait(0);
	}
}