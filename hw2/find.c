#include <stdio.h>
#include <dirent.h>
#include <string.h>

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
                    searchdir(search, newPath);
                    }
                    
                    
    
            } 
            
        }
        closedir(dr);
         
}


int main(int argc, char *argv[]){
    if (argc < 2)
    {
        printf("No search string provided\n");
        return 0;
    }
        searchdir(argv[1], ".");  
    return 0;
}