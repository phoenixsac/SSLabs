#include<fcntl.h>
#include<stdio.h>

int main(){
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int fdescVal=creat("testfile",mode);
	if(fdescVal==-1)
		printf("Error in creating file.");
	else
		printf("file descriptor value : %d",fdescVal);
}
