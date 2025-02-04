#include "../header/sh_inter.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

#define SH_READ_BUFFER 32
#define SH_DELIMITER " \t\r\n\a"

char *sh_read_line(void)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1) {
        if (feof(stdin)) {
            exit(EXIT_FAILURE);
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


int sh_execute(char **args)
{
    int status;
    pid_t process_id;
    process_id = fork();
    
    if (process_id == 0) { // child process
        printf("Child Process%d\n", process_id);
        if (execvp(args[0], args) == -1) { // execute a new program via vector path
            perror("Failed to execute new program.");
        }
    } else if (process_id < 0) {
        perror("error creating new process: fork");
        return EXIT_FAILURE;
    } else { // parent process
        do {
            waitpid(process_id, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
};


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

    } while(status); {
    }

    free(line);
    free(args);
}
