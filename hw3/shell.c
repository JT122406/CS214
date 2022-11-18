#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline(){
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    return line;
}

int main(){
    int i;
    char *exit_stuff = "exit\n";
    //int isExit = 1;
    do{
        printf("> ");
        char *line = readline();
        if (!strcmp("exit\n", line)){
            printf("this should exit\n");
            free(line);
            //very important check strings with a \n get line adds it to the end of a string
            return 0;
        }


        printf("%s", line);
        free(line);
    }while(1);
    
    
}