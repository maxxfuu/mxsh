#include "header/sh_inter.h"

#define SH_READ_BUFFER 1024;

// Read, Parse, Execute
char *sh_read_line(void) {
    
}

/*
char *sh_split_lint(char *line);
int sh_execute(char **args);
*/

void sh_loop(void) {
    char *line;
    char *args[];
    int status;

    do {
        printf("> ");
        line = sh_read_line();
        args = sh_split_lint(line);
        status = sh_execute(args);
    } while(1) {
        // something happens then breaks
        //
        break;
    }
}
