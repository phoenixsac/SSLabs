#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	struct timeval tval;
	fd_set rdfds;
	int time=10;

	FD_ZERO(&rdfds);
	FD_SET(STDIN_FILENO, &rdfds);

	tval.tv_sec=time;
	tval.tv_usec=0;

	int ret=select(STDIN_FILENO, &rdfds, NULL, NULL, &tval);

	if(ret==-1){
		perror("select error");
		return 1;
	}
	else if(ret==0){
		printf("%d seconds elapsed. \n",time);
		return 0;
	}
	else{
		printf("Data is available.");
		if(FD_ISSET(STDIN_FILENO, &rdfds)){
			printf("Stdin is ready with data for reading.");
		}	
	}


}
