#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h> 

int main() {
    const char *pipe_name = "myfifo";
    
    if (mkfifo(pipe_name, 0644) == -1) {
        perror("Error creating FIFO");
    } else {
        printf("FIFO created successfully.\n");
    }
    
    return 0;
}
