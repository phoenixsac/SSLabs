#include <stdio.h>
#include <unistd.h>
int main(){
	const char* targetfile="samplefile";
	const char* link_type="hardlink";
	if(link(targetfile,link_type)==-1){
		perror("Some error occured");
		return 1;
		}
	return 0;
}