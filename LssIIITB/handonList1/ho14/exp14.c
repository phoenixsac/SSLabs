
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Enter file path.");
		return 1;
	}

	char *filepath=argv[1];
	struct stat fInfo;

	if(stat(filepath,&fInfo)==-1){
		perror("Error.");
		return 1;
	}

    printf("\nfile type : %d",fInfo.st_mode);

	if (S_ISREG(fInfo.st_mode)) {
        printf("%s is a regular file.\n", filepath);
    } else if (S_ISDIR(fInfo.st_mode)) {
        printf("%s is a directory.\n", filepath);
    } else if (S_ISCHR(fInfo.st_mode)) {
        printf("%s is a character special file.\n", filepath);
    } else if (S_ISBLK(fInfo.st_mode)) {
        printf("%s is a block special file.\n", filepath);
    } else if (S_ISFIFO(fInfo.st_mode)) {
        printf("%s is a FIFO (named pipe).\n", filepath);
    } else if (S_ISSOCK(fInfo.st_mode)) {
        printf("%s is a socket.\n", filepath);
    } else if (S_ISLNK(fInfo.st_mode)) {
        printf("%s is a symbolic link.\n", filepath);
    } else {
        printf("%s is of unknown type.\n", filepath);
    }

    return 0;
}