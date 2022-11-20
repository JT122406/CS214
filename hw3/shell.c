#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    //int i;
    //char *exit_stuff = "exit\n";
    //int isExit = 1;
    char *line = NULL;
    do{
        printf("> ");
        size_t len = 0;
        if(getline(&line, &len, stdin) == EOF  || !strcmp("exit\n", line))
            break;
         //very important check strings with a \n get line adds it to the end of a string
        printf("%s", line);
        free(line);
    }while(1);
    free(line);
    return 0;
    
}