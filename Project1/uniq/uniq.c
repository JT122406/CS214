#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char* line;
    int freq;
    struct node* next;
};

typedef struct node node_data;

node_data *create_new_node(char* value){
    node_data *result = malloc(sizeof(node_data));
    result->line = value;
    result->freq = 1;
    result->next = NULL;
    return result;
}

int main(int argc, char *argv[])
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    //very important this is how you should be declaring your nodes
    //your nodes are technically a pointer to a pointer

    head->line = "poop";
    node_data *ptr = head;
    char line[100];
    while (scanf("%s", line) != EOF) { //Reads in the string to search
        if(head->next == NULL){
            head->next = create_new_node(line);
        } else{
            int boolean = 0;
            node_data* temp = head->next;
            while (temp->next != NULL){
                if(temp->next->line == line){
                temp->next->freq++;
                boolean = 1;
                    break;
                }
                temp = temp->next;
            }
            if(boolean == 0)
                ptr->next = create_new_node(line);
            boolean = 0;
        }
        ptr = ptr->next;
        printf("%c", ' '); 
    }
    //free(ptr);
    while(head->next != NULL){
        printf("%d",head->next->freq);
        printf("%c", ' ');
        printf("%s", head->next->line);
        printf("%c", '\n');
    }
    //free(head);
}