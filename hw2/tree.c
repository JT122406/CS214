#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]){
DIR *directory;
struct dirent *entry;
directory = opendir(".");
if(directory == NULL){
    return 1;
}
while((entry = readdir(directory)) != NULL){
    printf("- %s\n", entry->d_name);
}
closedir(directory);
//this is an addition
return 0;
}