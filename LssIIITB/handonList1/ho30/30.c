#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>

int main() {
    int pid;
    pid = fork();

    
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);
    
    if (setsid() < 0) {
        perror("setsid failed");
        exit(EXIT_FAILURE);
    }

    
    chdir("/");

    // Close standard file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    int hours,mins;
    printf("Enter time in HH:MM format : ");
    scanf("%d %d",&hours,&mins);

    // Now, the child process is a daemon running in the background
    while (1) {
        time_t now;
        struct tm *tm_info;

        // Get the current time
        time(&now);
        tm_info = localtime(&now);

        // Check if it's the desired time (e.g., 08:00 AM)
        if (tm_info->tm_hour == hours && tm_info->tm_min == mins) {
            // Replace "/path/to/your/script.sh" with the path to your script
            //execl("/bin/bash", "bash", "/path/to/your/script.sh", (char *)0);
            system();
            // If execl fails, log the error and exit
            perror("execl failed");
            exit(EXIT_FAILURE);
        }

        // Sleep for a while (e.g., 1 minute) before checking the time again
        sleep(60);
    }

    // The daemon process should never reach this point
    return 0;
}
