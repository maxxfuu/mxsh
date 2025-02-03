#include "../header/sh_inter.h"
#include <stdio.h>
#include <errno.h>

#define SH_READ_BUFFER 32

// Read
char *sh_read_line(void)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1) {
        if (feof(stdin)) {
            exit(1);
        }
    } else {
        perror("readline");
        exit(EXIT_FAILURE);
    }
    
    return line;
}

char **sh_split_lint(char *line)
{
    int buffer = SH_READ_BUFFER;
    int position = 0;
    char **tokens = malloc(sizeof(char*) * buffer);
    char *token;

    if (!token) {
        fprintf(stderr, "mxsh: alocation failed");
        exit(EXIT_FAILURE);
    }

    token 

};


/*
int sh_execute(char **args) {};
*/


void sh_loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = sh_read_line();
        args = sh_split_lint(line);
        status = sh_execute(args);
    } while(1); {
    }
}
