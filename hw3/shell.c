#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


char dir[1044];

void free_array(char** array, int argv){
    for(int i = 0; i < argv; i++){
        free(array[i]);
    }
    free(array);
}

struct Node {
struct Node *next;
struct Node *child;
int proc_id;
int sys_id;
int status;
int arg_num;
int is_backround;
char **arguments;
//gonna have to fix the two dimensional array no work good in C in struct
};

//void free_arguments(int i, char ** args){
//}
//need to free arrays later
void free_Node(struct Node *head){
if(head->child != NULL){
    free_Node(head->child);
}
if(head->next != NULL){
    free_Node(head->next);
}
free(head);
}

struct Node* create_node(int proc, int sys, int stat, int args){
    struct Node* head = malloc(sizeof(struct Node));
    head->next = NULL;
    head->child = NULL;
    head->proc_id = proc;
    head->sys_id = sys;
    head->status = stat;
    head->arg_num = args;
    head->arguments = malloc((sizeof(*head->arguments)) * args);
    return head;
}

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
		if (((str[i] != ' ') && (str[i] != 'c' ) && (str[i] != 'd')))
            str[j++] = str[i];
        
		i++;
	}
	str[j] = '\0';
	return str;
}

int number_of_arguments(char *string){
    int count = 1; //Always at least one argument
    for(int i = 0; (string[i + 1] != '\0'); i++){
        if(string[i] == ' ' && string[i+1] != ' '){
            count++;
            i++;  //we know the next one is starting the word so we can skip it
        }
    }
    return count;
}

char** stringsplit(char* string, int argv, char** save){
    int i = 0;
    char* token = strtok(string, " ");
    while(token != NULL){
        save[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    free(token);
    return save;
}

void cd_handler(char *line){
    remove_cd_white(line);  
    chdir(line);
    getcwd(dir, 1024);
    printf("%s", dir);
}

void command_handler(char *line){
    int arguments = number_of_arguments(line);
    char** args = malloc(arguments * sizeof(char*));
    stringsplit(line, arguments,  args);
    if(fork() == 0){
        if (execvp(args[0], args) < 0){
            printf("%s", args[0]);
            printf( ": command not found");
            printf("\n");
        }
        free_array(args, arguments);
        exit(0);
    }
    else{
        wait(NULL);
    }
}

void jobs_handler(){

}

void kill_handler(char *line){

}

void fg_handler(char *line){

}

void bg_handler(char *line){

}



int main(){
    char *line = NULL;
    getcwd(dir, 1024);
    do{
        size_t len = 0;
        printf("> ");
        
        if(getline(&line, &len, stdin) == EOF || !strcmp("exit\n", line) || strstr(line, "exit ") != NULL || strstr(line, " exit") != NULL)  //Exit Handler
            break;

        line[strcspn(line, "\n")] = '\0';
        remove_white_spaces_before(line);
        
        if (strstr(line, "cd ") != NULL){  //handles cd command
            cd_handler(line);
        } else if (strstr(line, "bg ") != NULL){  //handles bg command
            bg_handler(line);
        } else if (strstr(line, "fg ") != NULL){  //handles fg command
            fg_handler(line);
        } else if (strstr(line, "jobs") != NULL)  {//handles jobs command
            jobs_handler();
        } else if (strstr(line, "kill ") != NULL){  //handles kill command
            kill_handler(line);
        }else{  //running tasks
            command_handler(line);
        }


    free(line);
    }while(1);
    free(line);
    printf("\n");
    return 0;
}