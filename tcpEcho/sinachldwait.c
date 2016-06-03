#include "unp.h"

void
sig_chld(int signo)
{
    pid_t pid;
    int stat;
    while( pid = Waitpid(-1, &stat, WNOHANG) > 0){
        printf("child %d terminated.\n",pid);
    }
    return;
}
