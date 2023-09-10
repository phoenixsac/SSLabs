/*
============================================================================
Name : 2.c
Author : Sachin Nair
Description : . Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 09th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
int main(){
	while(1){
		sleep (5); 
		printf("Inside the loop..");
	}
}
