#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>

#define MAX_LIMIT 200

void handle_sigint(int sig)
{
    printf("Terminated.\n");
    exit(0);
}

int main(void)
{
    const char *homedir;

    if ((homedir = getenv("HOME")) == NULL)
    {
        homedir = getpwuid(getuid())->pw_dir;
    }

    char config_filename[MAX_LIMIT];
    strcpy(config_filename, homedir);
    strcat(config_filename, "/.nonshell_config");
    // printf("%s\n", config_filename);
    FILE* config_file = fopen(config_filename, "r");
    char filetext[MAX_LIMIT] = "";
    char ch;
    // while(filetext != NULL)
    // {
        fgets(filetext, MAX_LIMIT, config_file);
        printf("%s", filetext);
        // ch = fgetc(config_file);
        // printf("%c", ch);
    // }
    fclose(config_file);
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