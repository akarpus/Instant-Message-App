#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include "Header.h"

int main(int argc, char *argv[])
{
  while(1) 
  {
    if (argc > 1) 
    {
      user2(argv[1]);	
    }
    else
      user1();
  }
  return(0);
}

/*   Function:  user1()                         	*/
/*   Purpose:   Create and bind socket.  		*/
/*              Wait for a connection to opponent. 	*/
/*             	Read user2 message and respond.		*/
void user1()
{
int myListenSocket, user2Socket;
  struct sockaddr_in  myAddr, user2Addr;
  int i, addrSize, bytesRcv;
  int count = 1;

  char buffer[MAX_STR];

/* Create socket */
  myListenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (myListenSocket < 0) 
  {
  	printf("Could not open socket.\n");
	exit(-1);
  }

/* Setup user1 server address */
  memset(&myAddr, 0, sizeof(myAddr));
  myAddr.sin_family = AF_INET;
  myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  myAddr.sin_port = htons((unsigned short) SERVER_PORT);

/* Bind user1 listen socket */
  i = bind(myListenSocket, (struct sockaddr *) &myAddr,sizeof(myAddr));
  
  if (i < 0) 
  {
    printf("Could not bind socket.\n");
    exit(-1);
  }

/* Listen */
  i = listen(myListenSocket, 5);
  if (i < 0) 
  {
    printf("Could not listen.\n");
    exit(-1);
  }

/* Wait for connection request */

  addrSize = sizeof(user2Addr);
  user2Socket = accept(myListenSocket,(struct sockaddr *) &user2Addr,&addrSize);

  if (user2Socket < 0) 
  {
    printf("Could not accept the connection.\n");
    exit(-1);
  }

/* Read message from user2 and do something with it */
  while (1) 
  {
    oracle_Signal = 0;
    bytesRcv = recv(user2Socket, buffer, sizeof(buffer), 0);
    buffer[bytesRcv] = 0;
    printf("User 1:"  %s\n", buffer);
  } 

/* Close sockets */

  close(myListenSocket);
  close(user2Socket);
}

/*   Function:  user2()       	                 	*/
/*         in:  IP Address	    		        */
/*    Purpose:  Create, setup and connect to user1. 	*/
/*              Get input from user2 and send to user1. */
/*             	Close socket.				*/
void user2(char *arg)
{
  int mySocket;
  struct sockaddr_in  addr;
  int i, input;
  int count = 1;

  char inStr[MAX_STR];
  char buffer[MAX_STR];

/* Create socket */
  mySocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (mySocket < 0) {
    printf("Could not open socket.\n");
    exit(-1);
  }

/* Setup address */
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(arg);
  addr.sin_port = htons((unsigned short) SERVER_PORT);

/* Connect to server */

  i = connect(mySocket, (struct sockaddr *) &addr, sizeof(addr));

  if (i<0) 
  {
  	printf("User could not connect.\n");
  	exit(-1);
  }

/* Get input from user2 and send to server */
  while (1) 
  {
	gets(inStr);
  	strcpy(buffer, inStr);
    	send(mySocket, buffer, strlen(buffer), 0);
  } 

/* Close the socket */
  close(mySocket);
}

