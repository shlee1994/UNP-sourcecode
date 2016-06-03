#include "unp.h"

void str_cli(FILE *p, int sockfd)
{
  char sendline[MAXLINE], recivedline[MAXLINE];
  int maxfdl1;
  int stdineof = 0;
  int n;
  fd_set set;

  FD_ZERO(&set);
  for(; ; )
  {
      if(stdineof == 0)
          FD_SET(fileno(p), &set);
      FD_SET(sockfd, &set);
      maxfdl1 = max(fileno(p), sockfd) + 1;

      Select(maxfdl1, &set, NULL, NULL, NULL);
      if(FD_ISSET(sockfd, &set)) // socket is readable.
      {
         if( (n = Read(sockfd, recivedline, MAXLINE)) == 0)
         {
            if(stdineof ==1)
                return;
            else
                err_quit("error : server terminated prematural.");
         }
         Write(fileno(stdout), recivedline, n);
      }

      if(FD_ISSET(fileno(p), &set)) //input is readable.
      {
          if( (n = Read(fileno(p), sendline, MAXLINE)) == 0)
          {
              stdineof = 1;
              shutdown(sockfd, SHUT_WR);
              FD_CLR(fileno(p), &set);
              continue;
          }
          Writen(sockfd, sendline, n);
      }
  }
}
