#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <pwd.h>
#include <grp.h>

void searchdir(char* search, DIR *dr, char* currentdir){
        struct dirent *de;
        while ((de = readdir(dr)) != NULL)  //Linked List of nodes
        {
            if ((de->d_name[0] != '.'  || (de->d_name[1] == '.' && de->d_name[0] != '.' ))){
                if (de->d_type == DT_REG )  //file
                {
                    printf("./%s", currentdir);
                    printf("%s\n", de->d_name);
                }
            } else if (de->d_type == DT_DIR) //folder
            {
                searchdir(search, opendir(de->d_name), strcat(currentdir, strcat(de->d_name, "/")));
            }
        }
        closedir(dr); 
}


int main(int argc, char *argv[]){
        char* search = argv[1]; 
        DIR *dr = opendir(".");
        struct dirent *de;
        char* currentdir;
        while ((de = readdir(dr)) != NULL)  //Linked List of nodes
        {
            if ((de->d_name[0] != '.'  || (de->d_name[1] == '.' && de->d_name[0] != '.' ))){
                if (de->d_type == DT_REG)  //file
                {
                    if (strstr(de->d_name, search) != NULL)  //contains search string
                    {
                        printf("./");
                        printf("%s\n", de->d_name);
                    }
                    
                } else if (de->d_type == DT_DIR) //folder
                {
                    searchdir(search, dr, currentdir);
                }
            }
        }
        closedir(dr);   
    return 0;
}