#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *remove_white_spaces_before(char *str)
{
	int i = 0, j = 0;
    int boolean = 0;
	while (str[i])
	{
		if (str[i] != ' ' || boolean){
            str[j++] = str[i];
            boolean = 1;
        }
          
		i++;
	}
	str[j] = '\0';
	return str;
}


char *remove_cd_white(char *str)
{
	int i = 0, j = 0;
	while (str[i])
	{
		if (((str[i] != ' ') && (str[i] != 'c' )&& (str[i] != 'd')))
            str[j++] = str[i];
        
		i++;
	}
	str[j] = '\0';
	return str;
}


int main(){
    char *line = NULL;
    char dir[1044];
    getcwd(dir, 1024);
    do{
        printf("> ");
        size_t len = 0;
        if(getline(&line, &len, stdin) == EOF  || !strcmp("exit\n", line)  || strstr(line, "exit ") != NULL)
            break;
         //very important check strings with a \n get line adds it to the end of a string
        line[strcspn(line, "\n")] = '\0';
        remove_white_spaces_before(line);
        if (strstr(line, "cd ") != NULL){
            remove_cd_white(line);  
            chdir(line);
            getcwd(dir, 1024);
            printf("%s", dir);
            free(line);
            continue;
        }
        free(line);
    }while(1);
    free(line);
    printf("\n");
    return 0;
    
}