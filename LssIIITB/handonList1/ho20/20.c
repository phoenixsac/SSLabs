/*
============================================================================
Name : 20.c
Author : Sachin Nair
Description :  Find out the priority of your running program. Modify the priority with nice command.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
	int pid=getpid();
	printf("Process id is : %d\n",pid);
	int prior=getpriority(PRIO_PROCESS,pid);

	printf("Nice value of process is : %d\n",prior);
	int i=5;

	int modPrioVal=10;

	setpriority(PRIO_PROCESS,pid,modPrioVal);
	prior=getpriority(PRIO_PROCESS,pid);

	printf("Nice value of process after modification is : %d",prior);
	return 0;
}