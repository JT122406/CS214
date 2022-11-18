#include <stdio.h>

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
        

        free(line);
    }while(1);
    
    
}