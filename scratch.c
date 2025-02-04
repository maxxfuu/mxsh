#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define SH_DELIMITER " \t\r\n\a"

int main(int argc, char *argv[])
{   
    // test strtok()
    /* if (argc != 2) {
        printf("Arguments needs to be 2, you entered %d\n", argc);
        return 1;
    }

    char *string;
    string = strtok(argv[1], SH_DELIMITER);
    printf("Tokenized String: %s\n", string);
    */
    
    // test processes
    pid_t process_id;
    process_id = fork();
    
    if (process_id == 0) {
        printf("Child Process: %d\n", process_id);
    } else {
        printf("Parent Process: %d\n", process_id);
    }

    return 0;
}
