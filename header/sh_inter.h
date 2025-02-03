#ifndef SH_INTER
#define SH_INTER

#include <stdio.h>

char *sh_read_line(void);
char **sh_split_lint(char *line);
void sh_execute(char **args);

void sh_loop(void);

#endif
