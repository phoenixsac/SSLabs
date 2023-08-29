#include <stdio.h>
#include <unistd.h>
//#include <stdlib.h>
#include <fcntl.h>   // for the open() function
//#include <sys/types.h>
//#include <sys/stat.h>
int main(){
	int fd1=open("fl1",O_RDONLY | O_CREAT,0644);
	int fd2=open("fl2",O_RDONLY | O_CREAT,0644);
	int fd3=open("fl3",O_RDONLY | O_CREAT,0644);
	int fd4=open("fl4",O_RDONLY | O_CREAT,0644);
	int fd5=open("fl5",O_RDONLY | O_CREAT,0644);
	if(fd1==-1 || fd2==-1 || fd3==-1 || fd4==-1 || fd5==-1){
		perror("Error creating/opening file");
	}
	printf("fl1 : %d\n",fd1);
	printf("fl2 : %d\n",fd2);
	printf("fl3 : %d\n",fd3);
	printf("fl4 : %d\n",fd4);
	printf("fl5 : %d\n",fd5);

	int i=20;
	while(i){
		sleep(1);
		i--;
	}

	return 0;
}
