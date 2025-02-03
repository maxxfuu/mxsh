#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "sh_init.c"
#include "sh_inter.c"
#include "sh_term.c"

int main() {
    
    sh_loop();
    
    return EXIT_SUCCESS;
}
