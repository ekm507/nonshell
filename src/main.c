#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define MAX_LIMIT 20

void handle_sigint(int sig)
{
    printf("Terminated.\n");
    exit(0);
}

int main(void)
{
    signal(SIGINT, handle_sigint);  
    while(1)
    {
        char input[MAX_LIMIT];
        fgets(input, MAX_LIMIT, stdin);
    }

    return 0;
}