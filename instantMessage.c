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

// Final Code To Be Added
