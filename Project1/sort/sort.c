#include <stdio.h>
#include <ctype.h>


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

int numeric(){  //called when doing a numeric sort
    int current = 0;
    int* array = malloc(sizeof(int));
    while (scanf("%d", current) != EOF){
        int i = 0;
        array[i] = current;
        i++; 
        array = realloc(array, sizeof(int) * (i + 1));
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