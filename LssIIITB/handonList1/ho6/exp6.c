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
