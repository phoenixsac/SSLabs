/*
============================================================================
Name : 15.c
Author : Sachin Nair
Description : Write a program to display the environmental variable of the user (use environ).
Date: 10th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
extern char **environ;
int main(){
	//pointer to char pointers
	char **env=environ;
	int i=0;
	while (*env) {
        	printf("%s\n", *env);
        	env++;
    }
}