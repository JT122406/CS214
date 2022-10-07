#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void numeric(){  //called when doing a numeric sort
    int current;
    int* array = malloc(sizeof(int) * 100);
    int i = 0;
    while (scanf("%d", &current) != EOF){
        array[i] = current;
        i++; 
    }
    for (int k = 0; k < i; k++)
    {
        for (int j = 0; j < sizeof(array); j++)
        {
            if (array[k] < array[j]){
                int temp = array[k];
                array[k] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int q = 0; q < i; q++)
    {
        printf("%d", array[q]);
        printf("%c", '\n');
    }
}

void alphabetical(){
    char current [100][100]; //current line
    int i = 0;
    while (scanf("%s", current[i]) != EOF  && i < 100){
        i++;
    }  //simply reads in the lines

    for (int k = 0; k < i; k++)
    {
        for (int j = 0; j < i; j++)
        {
            if (strcmp(current[k], current[j]) < 0){
                char temp [100];
                strcpy(temp, current[k]);
                strcpy(current[k], current[j]);
                strcpy(current[j], temp);
            }
        }
    }

    for (int q = 0; q < i; q++)
    {
        printf("%s", current[q]);
        printf("%c", '\n');
    }
}


int main(int argc, char *argv[]){  

    if((argc < 2) || (*argv[1] == '\0')){  //Makes sure there is a string to search for
        alphabetical();
        return 0;
    }


    if ((argv[1][0] == '-'  && (argv[1][1] == 'n')))
        numeric();

        
    return 0;
}

