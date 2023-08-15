#include <stdio.h>
#include <unistd.h>
int main(){
	const char* targetfile="samplefile";
	const char* link="softlink";
	if(symlink(targetfile,link)==-1){
		perror("Some error occured");
		return 1;
		}
	return 0;
}