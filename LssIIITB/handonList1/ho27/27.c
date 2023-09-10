/*
============================================================================
Name : 27.c
Author : Sachin Nair
Description :    Write a program to execute ls -Rl by the following system calls
 a. execl
 b. execlp
 c. execle
 d. execv
 e. execvp
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Choose in which mode :-\n1.execl\n2.execlp\n3.execle\n4.execv\n5.execvp\n");
    int choice;
    scanf("%d",&choice);

    switch(choice){
        case(1):
            printf("Using execl:\n");
            if (execl("/bin/ls", "ls", "-Rl", NULL) == -1) {
                perror("execl");
                exit(EXIT_FAILURE);
            }
            break;

        
            case(2):
            printf("Using execlp:\n");
            if (execlp("ls", "ls", "-Rl", NULL) == -1) {
                perror("execlp");
                exit(EXIT_FAILURE);
            }
            break;

        
            case(3):
            printf("Using execle:\n");
            char *envp[] = {NULL}; // Empty environment
            if (execle("/bin/ls", "ls", "-Rl", NULL, envp) == -1) {
                perror("execle");
                exit(EXIT_FAILURE);
            }
            break;

        
            case(4):
            printf("Using execv:\n");
            char *args[] = {"/bin/ls", "ls", "-Rl", NULL};
            if (execv("/bin/ls", args) == -1) {
                perror("execv");
                exit(EXIT_FAILURE);
            }
            break;

        
            case(5):
            printf("Using execvp:\n");
            char *argsp[] = {"ls", "-Rl", NULL};
            if (execvp("ls", argsp) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
            break;
    }

    return 0; 
}
