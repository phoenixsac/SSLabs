#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main() {
    int pid = getpid(); 

    int  curr_policy = sched_getscheduler(pid);

    if ( curr_policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Current scheduling policy for PID %d is: ", pid);

    switch (curr_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    
    struct sched_param new_param;
    new_param.sched_priority = 99; 

    if (sched_setscheduler(pid, SCHED_FIFO, &new_param) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    // Verify the updated scheduling policy
     curr_policy = sched_getscheduler(pid);

    if ( curr_policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Updated scheduling policy for PID %d is: ", pid);

    switch ( curr_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    return 0;
}
