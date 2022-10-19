#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <pwd.h>
#include <grp.h>

struct node
{
    struct dirent *file;
    struct node* next;
    char* name;
};

typedef struct node node_data;

node_data *create_new_node(struct dirent *de){
    node_data *result = malloc(sizeof(node_data));
    result->file = de;
    result->next = NULL;
    if (de == NULL)
    {
        result->name = NULL;
        return result;
    }
    
    char* name = de->d_name;
    int i = 0;
    while(name[i]){
        name[i] = tolower(name[i]);
        i++;
    }
    result->name = name;
    return result;
}


char* month(int monthnum) {
    switch (monthnum) {
        case 0:
            return "Jan";
        case 1:
            return "Feb";
        case 2:
            return "Mar";
        case 3:
            return "Apr";
        case 4:
            return "May";
        case 5:
            return "Jun";
        case 6:
            return "Jul";
        case 7:
            return "Aug";
        case 8:
            return "Sep";
        case 9:
            return "Oct";
        case 10:
            return "Nov";
        case 11:
            return "Dec";
    }
    return "Invalid month";
}

void readwrite(struct stat buf){
    if (buf.st_mode & S_IRUSR)
        printf("r");
    else
        printf("-");
    if (buf.st_mode & S_IWUSR)
        printf("w");
    else
        printf("-");
    if (buf.st_mode & S_IXUSR)
        printf("x");
    else
        printf("-");
    if (buf.st_mode & S_IRGRP)
        printf("r");
    else
        printf("-");
    if (buf.st_mode & S_IWGRP)
        printf("w");
    else
        printf("-");
    if (buf.st_mode & S_IXGRP)
        printf("x");
    else
        printf("-");
    if (buf.st_mode & S_IROTH)
        printf("r");
    else
        printf("-");
    if (buf.st_mode & S_IWOTH)
        printf("w");
    else
        printf("-");
    if (buf.st_mode & S_IXOTH)
        printf("x");
    else
        printf("-");
}

void printDate(struct stat buf){
    struct tm dt;
    dt = *(gmtime(&buf.st_mtime));
    printf(" %s", month(dt.tm_mon));  //Prints the month
    printf(" %d", dt.tm_mday);  //Prints the day
    if (dt.tm_hour < 10)
        printf(" 0%d", dt.tm_hour);  //Prints the hour
    else
        printf(" %d", dt.tm_hour);  //Prints the hour

    if (dt.tm_min < 10)
        printf(":0%d ", dt.tm_min);  //Prints the minute
    else
        printf(":%d ", dt.tm_min);  //Prints the minute
    
    //printf(" %s %d %d:%d ", month(dt.tm_mon), dt.tm_mday,  dt.tm_hour, dt.tm_min);
}

void freeList(node_data* head)
{
   node_data* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}


 /* function to swap data of two nodes a and b*/
void swap(node_data *a, node_data *b) 
{
    struct dirent *file = a->file;
    //node_data* next = a->next;
    char* name = a->name;
    a->file = b->file;
   // a->next = b->next;
    a->name = b->name;
    b->file = file;
    //b->next = next;
    b->name = name;
} 
  
/* Bubble sort the given linked list */
void bubbleSort(node_data *start) 
{ 
    int swapped; 
    node_data *ptr1; 
    node_data *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (strcmp(ptr1->name, ptr1->next->name) > 0) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  




int main(int argc, char *argv[]){
    int info;
    if((argc < 2) || (*argv[1] == '\0')){  //Makes sure there is a string to search for
        info = 0;
    } else if (argv[1][0] == '-'  && argv[1][1] == 'l')
    {
        info = 1;
    }
    else
        return 0;

    
    DIR *dr = opendir(".");  //Opens current directory
    struct dirent *de;
    node_data *head = create_new_node(NULL);
    node_data *current = head;

        int count = 0;
        while ((de = readdir(dr)) != NULL)  //Linked List of nodes
        {
            if ((de->d_type == DT_REG  || de->d_type == DT_DIR)  && (de->d_name[0] != '.'  || (de->d_name[1] == '.' && de->d_name[0] != '.' ))){
                count++;
                current->next = create_new_node(de);
                current = current->next;
            }
        }
        //free(current);
        closedir(dr);   

        bubbleSort(head->next);
        node_data *temp = head;
        //now we should sort them

        
    while (temp->next !=  NULL){
        temp = temp->next;
        if (info == 1){
                    if (temp->file->d_type == DT_DIR)printf("d");
                    else printf("-");
                    struct stat buf;
                    stat(temp->file->d_name, &buf);
                    readwrite(buf);
                    printf(" %s %s ", getpwuid(buf.st_uid)->pw_name, getgrgid(buf.st_gid)->gr_name);
                    printf("%ld", buf.st_size);
                    printDate(buf);
        }
        printf("%s\n", temp->file->d_name); 
    }

    freeList(head);
    
        
/*
        for (int i = 0; i < count; i++)  //Print Loop
        {
            sorted = sorted->next;
            if (info == 1)  //print file info before file name
                    {
                        struct stat buf;
                        if (sorted->file->d_type == DT_DIR)printf("d");
                        else printf("-");
                        stat(sorted->file->d_name, &buf);
                        readwrite(buf);
                        printf(" %s %s ", getpwuid(buf.st_uid)->pw_name, getgrgid(buf.st_gid)->gr_name);
                        printf("%ld", buf.st_size);
                        printDate(buf);
                    }
                printf("%s\n", sorted->file->d_name);
                    
        }
        freeList(head);
        freeList(sorted);
        freeList(sorted);
        */
        return 0;
    }