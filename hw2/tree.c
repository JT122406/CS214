#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
struct Node *next;
struct Node *root;
char data[1000];
//struct dirent *data2;
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
//if(head-> data2 != NULL ){
//    closedir(opendir(head->data2->d_name));
//}
free(head);


}

//struct Node* 
void tree(char *basePath, const int root, struct Node* head);

struct Node* create_node(){
    struct Node* head4 = malloc(sizeof(struct Node));
    //head4->data =(char*) malloc(sizeof(char)*1000);
    //strcpy(head4->data, data4);
    head4->next = NULL;
    head4->root = NULL;
    head4->isDir = 0;
    head4->level = 0;
    //head4->data2 = file;
    return head4;
}

void swap(struct Node* node1, struct Node* node2, struct Node* head){
struct Node* temp = head;
if(node1->next != node2){
    return;
}
while(temp != NULL){
    if(temp->next->data == node1->data){
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        
        break;
    }
    else{
        temp = temp-> next;
    }
}
}

void bubbleSort(struct Node* start) 
{ 
    int swapped; 
    struct Node* ptr1; 
    struct Node* lptr = NULL; 
  
    /* Checking for empty list */
    if (start->next == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start->next; 
        if(ptr1->next == NULL)
        return;
  
        while (ptr1->next != lptr) 
        { 
            if (strcasecmp(ptr1->data, ptr1->next->data) > 0) 
            { 
                swap(ptr1, ptr1->next, start); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}











int main()
{

//struct Node* head = create_node();
struct Node* head = create_node(); 
tree(".", 0, head);
/*    
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
*/
    //bubbleSort(head);
    printf(".\n");
    //swap(head->next, head->next->next, head);
    //swap(head->next->next->next->next->next, head->next->next->next->next->next->next, head);
    print_Node(head->next);
    free_Node(head);
    
    return 0;
}



//struct Node* 
void tree(char *basePath, const int root, struct Node* head)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir){
        //head->isDir = 0;
        return;
    }
    //struct Node* new_node = create_node(NULL);
    struct Node* current = head;
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            //printf("%c%c%s\n", 195, 196, dp->d_name);
            //strcpy(current->data->d_name, dp->d_name);
            //new_node->data = dp;
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
            //current ->isDir = 1;
            //current ->next = new_node;
            
            //head-> next = tree(path, root + 1, new_node);
            //return head->next;
            //head = head -> next;
        }
        //current = head -> next;
        //tree(path, root, current->root);
    }

    closedir(dir);
    //return head;
}