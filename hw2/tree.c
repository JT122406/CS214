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

void print_Node(struct Node* head){
    struct Node* head2 = head;
    if(head2 == NULL)
    return;
    while(head2 != NULL){
        for(int i = 0; i < head2->level; i++){
        printf("  ");
        }
        printf("- %s\n", head2->data);
        if(head2->root!=NULL)
        print_Node(head2->root->next);
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
    head4->next = NULL;
    head4->root = NULL;
    head4->isDir = 0;
    head4->level = 0;
    return head4;
}

void swap(struct Node* node1,struct Node* node2){


char temp_string[1000];
strcpy(temp_string, node2->data);
strcpy(node2->data,node1->data);
strcpy(node1->data, temp_string);
if(node1->isDir || node2->isDir){
    int temp_int = node2->isDir;
    node2->isDir = node1->isDir;
    node1->isDir = temp_int;
    struct Node* temp_node1 = node1->root;
    struct Node* temp_node2 = node2->root;
    node1->root = temp_node2;
    node2->root = temp_node1;
}



}

void bubbleSort(struct Node* start) 
{ 
    int swapped; 
    struct Node* ptr1; 
    struct Node* lptr = NULL; 
  
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (strcasecmp(ptr1->data, ptr1->next->data) > 0) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            if(ptr1->isDir){
                bubbleSort(ptr1->root->next);
            }
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}











int main()
{


struct Node* head = create_node(); 
tree(".", 0, head);
bubbleSort(head->next);
printf(".\n");
print_Node(head->next);
free_Node(head);

return 0;
}



void tree(char *basePath, const int root, struct Node* head)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir){
        return;
    }
    struct Node* current = head;
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, "..") != 0 && strcmp(dp->d_name, ".") != 0)
        {
            current->next = create_node();
            strcpy(current->next->data, dp->d_name);
            current = current->next;
            current->level = root;
            
            if(dp->d_type == DT_DIR){
            current->isDir = 1;
            current->root = create_node();
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            tree(path,root+1,current->root);
            }
            
        }

    }

    closedir(dir);

}