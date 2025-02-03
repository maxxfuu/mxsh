#include "../header/sh_inter.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define SH_READ_BUFFER 32
#define SH_DELIMITER " \t\r\n\a"
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
    int buffer_size = SH_READ_BUFFER;
    int position = 0;
    char **tokens = malloc(sizeof(char*) * buffer_size);
    char *token;

    if (!tokens) {
        fprintf(stderr, "mxsh: allocation failed");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, SH_DELIMITER);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position > buffer_size) {
            buffer_size *= 2;
            tokens = realloc(tokens, buffer_size);
            if (!token) {
                fprintf(stderr, "mxsh: realloaction failed");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, SH_DELIMITER);
    }
    tokens[position] = NULL;
    return tokens;
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

    free(line);
    free(args);
}
