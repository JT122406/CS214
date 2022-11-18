#include <stdio.h>
#include <stdlib.h>

char* readline(){
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    return line;
}

int main(){
    do{
        printf("> ");
        char *line = readline();
        
        //printf("> %s", line);
        free(line);
    }while(1);
    
    
}