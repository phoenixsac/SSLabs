/*
============================================================================
Name : 27b.c
Author : Sachin Nair
Description : Write a program to receive messages from the message queue.
    a. with IPC_NOWAIT as a flag
Date: 14th Sept, 2023.
============================================================================
*/

#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

int main(void) {
    struct msg {
        long mtype;
        char mtext[20];
    } mq;
    key_t key = ftok(".", 2);
    int msgid = msgget(key, IPC_CREAT | 0600);

    printf("Enter msg type: ");
    scanf("%ld", &mq.mtype);

    msgrcv(msgid, &mq, sizeof(mq.mtext), mq.mtype, IPC_NOWAIT);
    printf("Message : %s\n", mq.mtext);

    return 0;
}