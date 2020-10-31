#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
    if (signo == SIGINT)
        printf("received SIGINT\n");
    else if (signo == SIGQUIT)
        printf("received SIGQUIT\n");
    else if (signo == SIGTSTP)
        printf("received SIGTSTP\n");
}

int main(void)
{
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");
    if (signal(SIGQUIT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGQUIT\n");
    if (signal(SIGTSTP, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGTSTP\n");
    // A long long wait so that we can easily issue a signal to this process
    while(1) 
        sleep(1);
    return 0;
}
