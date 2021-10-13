#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(void)
{
    void    f(int);
    void    g(int);
    int     i;

    signal(SIGUSR1, f);
    signal(SIGUSR2, g);
    i = 0;
    while (++i)
    {
        printf("%dsec\n", i);
        sleep(1);
    }
}