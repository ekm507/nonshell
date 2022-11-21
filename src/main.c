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
    char input[MAX_LIMIT];
    char *check_input;
    while(1)
    {
        check_input = fgets(input, MAX_LIMIT, stdin);
        if (check_input != NULL)
        {
            // printf("%s", input);
        }
        else
        {
            return 0;
        }
    }

    return 0;
}