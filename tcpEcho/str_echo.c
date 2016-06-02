#include "unp.h"

void str_echo(int connectfd){
	ssize_t n;
    char buff[MAXLINE];
again:
    while( (n = read(connectfd, buff, MAXLINE)) > 0)
        Writen(connectfd, buff, n);
	if( n < 0 && errno == EINTR)
		goto again;
	else if(n < 0)
		err_sys("error: read error.");

}

