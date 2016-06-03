#include "unp.h"
#include <time.h>

//void sig_chld(int);
int main(void)
{
    struct sockaddr_in servaddr, cliaddr;
    int listenfd, connfd, len;
    void sig_chld(int);

    pid_t child_pid;
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    Bind(listenfd, (SA*) &servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);
    Signal(SIGCHLD, sig_chld);
    for(;;)
    {
        len = sizeof(cliaddr);
        connfd = Accept(listenfd, (SA*)&cliaddr, &len);

        if( (child_pid = fork()) == 0){
            printf("pid id :%d\r\n", getpid());
            Close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        Close(connfd);
    }
}
