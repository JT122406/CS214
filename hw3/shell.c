#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    //int i;
    //char *exit_stuff = "exit\n";
    //int isExit = 1;
    char *line = NULL;
    char *dir = NULL;
    getcwd(&dir, 1024);
    do{
        printf("> ");
        size_t len = 0;
        if(getline(&line, &len, stdin) == EOF  || !strcmp("exit\n", line))
            break;
         //very important check strings with a \n get line adds it to the end of a string

        if (strstr(*line, "cd") != NULL)
        {
            
        }
         
        printf("%s", line);
        free(line);
    }while(1);
    free(line);
    printf("\n");
    return 0;
    
}