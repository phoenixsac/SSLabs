#include <stdio.h>
#include <unistd.h>
int main(){
	int par_id = getpid();
	int id=fork();
	if(id==0){
		printf("In child process.Parent id : %d\n",par_id);
		printf("In child process.Child id : %d\n",id);
	}
	else{
		printf("In parent process.ParentId : %d\n",par_id);
		printf("In parent process.Child Id : %d\n",id);
	}
}