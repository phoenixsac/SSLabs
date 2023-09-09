#include<stdio.h>
int main(){
	int id = fork();
	if(id==0){
		printf("In child process.\nId : %d\n\n",id);
	}
	else{
		printf("In parent process.\nParentId : %d",id);
	}
}