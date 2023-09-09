#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

void check_schedType(int curr_policy){
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
}

int main() {
    int pid = getpid(); 

    int  curr_policy = sched_getscheduler(pid);

    if ( curr_policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Current scheduling policy for PID %d is: ", pid);
    check_schedType(curr_policy);

    
    struct sched_param new_param;
    new_param.sched_priority = 99; 

    int choice;
    printf("Set scheduling to FIFO(1) or RR(2)?\n");
    scanf("%d",&choice);
    //char sched_type[20]

    if(choice==1){
        if (sched_setscheduler(pid, SCHED_FIFO, &new_param) == -1) {
            perror("sched_setscheduler");
            exit(EXIT_FAILURE);
        }
    }
    else if(choice==2){
          if (sched_setscheduler(pid, SCHED_RR, &new_param) == -1) {
            perror("sched_setscheduler");
            exit(EXIT_FAILURE);
        }
    }
    curr_policy = sched_getscheduler(pid);

  
    if ( curr_policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Updated scheduling policy for PID %d is: ", pid);

    check_schedType(curr_policy);

    return 0;
}
