#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
struct Node *next;
struct Node *root;
char data[1000];
int level;
int isDir;

};

void print_Node(struct Node* head2){
    if(head2 == NULL)
    return;
    while(head2 != NULL){
        for(int i = 0; i < head2->level; i++){
        printf("  ");
        }
        printf("- %s\n", head2->data);
        if(head2->isDir)
        print_Node(head2->root);
        head2 = head2->next;
    }
}
void free_Node(struct Node* head){
if(head->root != NULL){
    free_Node(head->root);
}
if(head->next != NULL){
    free_Node(head->next);
}
free(head);

}

void tree(char *basePath, const int root, struct Node* head);

struct Node* create_node(){
    struct Node* head4 = malloc(sizeof(struct Node));
    //head4->data =(char*) malloc(sizeof(char)*1000);
    //strcpy(head4->data, data4);
    head4->next = NULL;
    head4->root = NULL;
    head4->isDir = 0;
    head4->level = 0;
    return head4;
}

int main()
{

struct Node* head = create_node();
    //tree(".", 0, head);
struct Node* child = create_node();
struct Node* bext = create_node();
struct Node* child_next = create_node();
struct Node* next_next = create_node();
    strcpy(head->data, "hello");
    strcpy(child->data, "child");
    strcpy(bext->data, "this is next");
    strcpy(child_next->data, "this is child next");
    strcpy(next_next->data, "this is next next");
    head->next = bext;
    head->root = child;
    child->level++;
    head->isDir = 1;
    child_next->level++;
    child->next = child_next;
    bext->next = next_next;
    //bext->root = child;
    //bext->isDir = 1;
    //struct Node* test = head;
    print_Node(head);
    free_Node(head);

    return 0;
}



void tree(char *basePath, const int root, struct Node* head)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);


    if (!dir)
        return;
    struct Node* new_Node = create_node();
    struct Node* current = create_node();
    new_Node -> level = root;
    head->root = new_Node;
    head->isDir = 1;
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {

            strcpy(new_Node->data,dp->d_name);
            current = new_Node;
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            tree(path, root + 1, new_Node);
            new_Node = current -> next;
            
        }
    }

    closedir(dir);
}