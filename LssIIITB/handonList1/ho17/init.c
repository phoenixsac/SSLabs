#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[]){

    if(argc!=2){
        printf("Enter filename to store tickets");
    }
    char *filename=argv[1];
    int fd = open(filename,O_RDWR|O_TRUNC);

    if(fd==-1){
        perror("File culd not be opened.");
    }
    int tktInit=2000;
    char buff[256];
    snprintf(buff, sizeof(buff), "%d", tktInit);
    
    ssize_t bytesWrote = write(fd, buff, strlen(buff));
    if (bytesWrote == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    close(fd);
}