#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

struct Node {
struct Node *next;
struct Node *child;
int proc_id;
int sys_id;
int status;
int arg_num;
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
        size_t len = 0;
        printf("> ");
        if(getline(&line, &len, stdin) == EOF || !strcmp("exit\n", line) || strstr(line, "exit ") != NULL)
            break;
         //very important check strings with a \n get line adds it to the end of a string
        line[strcspn(line, "\n")] = '\0';
        remove_white_spaces_before(line);
        if (strstr(line, "cd ") != NULL){  //handles cd command
            remove_cd_white(line);  
            chdir(line);
            getcwd(dir, 1024);
            printf("%s", dir);
            free(line);
            continue;
        }  //Handle everything not cd out here
        char* argument_list[] = {"ls", "-l", NULL};
        pid_t pid;
        if((pid = fork()) == 0) execvp(line, argument_list);

        int status = 0;
        while ((pid = wait(&status)) > 0);
        free(line);
    }while(1);
    free(line);
    printf('\n');
    return 0;
    
}