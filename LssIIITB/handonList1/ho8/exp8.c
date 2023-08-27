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
	int ind;
	
	while((bytesRead=read(fd,&buffer,sizeof(buffer)))>0){
		if(buffer[0]=='\n'){
			lineBuff[ind]='\n';
			printf("%s\n",lineBuff);
			sleep(0.5);
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