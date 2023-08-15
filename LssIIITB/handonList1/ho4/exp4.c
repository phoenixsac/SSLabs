/*opening only an existing file in read write mode*/
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
int main(){
	int fdVal=open("existingFile",O_RDWR | O_EXCL,0600);
	if(fdVal==-1){
		if(errno==EEXIST)
			printf("File already exists.");
		else
			printf("Error opening file.");
	}
	else
	printf("File opened successfully.");
	return 0;
}

