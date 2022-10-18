#include <stdio.h>
#include <dirent.h>
#include <string.h>

void tree(char *basePath, const int root);

int main()
{


    tree(".", 0);

    return 0;
}



void tree(char *basePath, const int root)
{
    int i;
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            for (i=0; i<root; i++) 
            {

                printf("  ");

            }

            printf("- %s\n", dp->d_name);

            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            tree(path, root + 1);
        }
    }

    closedir(dir);
}