#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	
	if(argc!=2)
		printf("Enter filename as argument.");
	//file open
	char *flname = argv[1];
	int fd=open(flname, O_RDWR);
	//file open check
	if(fd==-1)
		printf("File could not be opened successfully.");
	//set bytes to write
	char dtw1[10]="qwertyuiop";
	
	
	//write to file
	ssize_t bytesWritten=write(fd,dtw1,sizeof(dtw1));
	
	//check write
	if(bytesWritten==-1){
		perror("Error in writing to file.");
		close(fd);
		return 1;
	}
	//set seek value
	off_t newPos=lseek(fd,10,SEEK_SET);
	
	if(newPos==-1){
		perror("lseek error");
		close(fd);
		return 1;
	}
	
	//write to file
	char dtw2[10]="asdfghjkla";
	
	bytesWritten=write(fd,dtw2,10);
	
	if(bytesWritten==-1){
		perror("Write error.");
		close(fd);
		return 1;
	}
	
	
	//close fd
	close(fd);
	printf("File operations completed successfully.");
}

/*OUTPUT of od -c
0000000   q   w   e   r   t   y   u   i   o   p   a   s   d   f   g   h
0000020   j   k   l   a
0000024
*/