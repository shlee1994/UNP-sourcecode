#include "unp.h"

void str_cli(FILE *p, int sockfd)
{
  char sendline[MAXLINE], recivedline[MAXLINE];

  while(Fgets(sendline, MAXLINE, p) != NULL)
  {
      Writen(sockfd, sendline, strlen(sendline));

      if(Read(sockfd, recivedline, MAXLINE) == 0)
          err_quit("server terminate prematurally");
      Fputs(recivedline,stdout);
  }
}
