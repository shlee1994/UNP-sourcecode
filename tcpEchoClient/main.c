#include "unp.h"

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;
    int sockfd;

   // if(argc != 2)
    //    err_quit("usage: tcpcli <ipaddress>");

    argv[1] = "127.0.0.1";
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);

    sockfd = Socket(AF_INET, SOCK_STREAM, 0) ;

    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    Connect(sockfd, (SA*)&servaddr, sizeof(servaddr));

    str_cli(stdin, sockfd);
    exit(0);
}