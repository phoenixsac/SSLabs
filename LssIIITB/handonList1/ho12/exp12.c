#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Filename and mode not specified.");;
        return 1;
    }

    const char *filename = argv[1];

    int fd = open(filename, O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);

    if (flags == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }
    
    printf("%d : ",flags);

    switch(flags & O_ACCMODE){
        case O_RDONLY:
            printf("Opening in read only mode.");
            break;
        case O_WRONLY:
            printf("Opening in write only mode.");
            break;
        case O_RDWR:
            printf("Opening in read write mode.");
            break;
        default:
            printf("Unknown opening mode.");
    }

    close(fd);
    return 0;
}
