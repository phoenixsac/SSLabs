/*
============================================================================
Name : 32d.c
Author : Sachin Nair
Description :Write a program to implement semaphore to protect any critical section.
d. remove the created semaphore
Date: 14th Oct, 2023.
============================================================================
*/

#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	struct sockaddr_in server, client;

	int sd, sz, nsd;
	char buf[80];

	sd = socket(AF_UNIX, SOCK_STREAM, 0);

	server.sin_family = AF_UNIX;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(5555);

	bind(sd, (void *)(&server), sizeof(server));

	listen(sd, 5);
	sz = sizeof(client);
	nsd = accept(sd, (void *)(&client), &sz);

	read(nsd, buf, sizeof(buf));
	printf("Message from Client : %s\n", buf);
	
	write(nsd, "ACK from Server\n", 17);

	return 0;
}