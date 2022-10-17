#include <stdio.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[]){
    int info;
    if((argc < 2) || (*argv[1] == '\0')){  //Makes sure there is a string to search for
        info = 0;
    } else if (argv[1][0] == '-'  && argv[1][1] == 'l')
    {
        info= 1;
    }
    else
        return 0;


    struct dirent *de;
    DIR *dr = opendir(".");
    while ((de = readdir(dr)) != NULL)
    {
        if (de->d_type == DT_REG)
            {
                printf("%s\n", de->d_name);
            }
    }
            
  
    closedir(dr);    
    return 0;
    

}