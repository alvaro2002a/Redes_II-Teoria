#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#include "utils.h"
#include <asm-generic/socket.h>



int main()
{
  int client_fd,new_socket;
  struct sockaddr_in address;
  FILE *file;
  

  /* Crear descriptor de fichero de socket */ 
  if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
     perror("socket");
     exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_port = htons(PORT);


  if(inet_pton(AF_INET,))







}
