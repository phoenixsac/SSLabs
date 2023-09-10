/*
============================================================================
Name : 25.c
Author : Sachin Nair
Description :   Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call)
============================================================================
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int ch_ids[3];
	int i=2;
	printf("id: %d\n",getpid());
	while(i>=0){
		ch_ids[i]=fork();
	
		if(ch_ids[i]==-1){
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if(ch_ids[i]==0){
			printf("In child process %d.Id : %d\n",i,getpid());
			sleep(2);
			printf("Child process %d done.\n",i);
			//imp or else heirarchically calls new forks and creates new child processes
			exit(EXIT_SUCCESS);
		}
		i--;
	}

	
	int chpr_to_waitfor=ch_ids[0];

	int term_child_id=waitpid(chpr_to_waitfor,NULL,0);
	printf("Waited for pid : %d\n",term_child_id);

    return 0;

}