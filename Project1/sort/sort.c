#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int numeric(){  //called when doing a numeric sort
    int* current = malloc(sizeof(int));
    int* array = malloc(sizeof(int));
    int i = 0;
    while (scanf("%d", current) != EOF){
        array[i] = current[0];
        current[0] = '\0';
        i++; 
    }
    for (int i = 0; i < sizeof(array); i++)
    {
        for (int j = 0; j < sizeof(array); j++)
        {
            if (array[i] < array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int i = 0; i < sizeof(array); i++)
    {
        printf("%d", array[i]);
        printf("%c", '\n');
    }
}


int main(int argc, char *argv[]){    
    if((argc < 2) || (*argv[1] == '\0')){  //If a command line input is there 
        char* search = argv[1]; //The string to search for and if we are case sensetive
        if (argv[1][0] == '-'  && argv[1][1] == 'n'){
            numeric;
            return 0;
        }  
    }

    char line[100];
    while (scanf("%s", line) != EOF){

    }

}

