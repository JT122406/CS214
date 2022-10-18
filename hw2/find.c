#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void searchdir(char* search, char* directory){
        DIR *dr = opendir(directory); 
        char newPath[1000];
        if (!dr)
        {
            return;
        }
        
        struct dirent *de;
        while ((de = readdir(dr)) != NULL)  //Linked List of nodes
        {
            
            if ((de->d_name[0] != '.'  || (de->d_name[1] == '.' && de->d_name[0] != '.' ))){
                
              
                    if (strstr(de->d_name, search) != NULL)  //contains search string
                    {
                        printf("./%s", directory);
                        printf("%s\n", de->d_name);
                    }
                    if (de->d_type != DT_REG)
                    {
                        if (directory[0] != '.')
                            {
                                strcpy(newPath, directory);
                                strcat(newPath, de->d_name);
                                strcat(newPath, "/");
                            }
                            else{  //first directory
                                strcpy(newPath, de->d_name);
                                strcat(newPath, "/");
                            }
                    
                    
                    //printf("\n%s\n", newPath);
                    searchdir(search, newPath);
                    }
                    
                    
    
            } 
            
        }
        closedir(dr);
         
}


int main(int argc, char *argv[]){
        searchdir(argv[1], ".");
        /*
        struct dirent *de;
        char* currentdir;
        while ((de = readdir(dr)) != NULL)  //Linked List of nodes
        {
            if ((de->d_name[0] != '.'  || ((strlen(de->d_name) >= 2)&&(de->d_name[1] == '.' && de->d_name[0] != '.' )))){
                if (de->d_type == DT_REG)  //file
                {
                    if (strstr(de->d_name, search) != NULL)  //contains search string
                    {
                        printf("./");
                        printf("%s\n", de->d_name);
                    }
                    
                } else if (de->d_type == DT_DIR) //folder
                {
                    searchdir(search, opendir(strcat("./",de->d_name)), currentdir);
                }
            }
        }
        */
        //closedir(dr);   
    return 0;
}