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


int main(int argc, char *argv[]){    
    if ((argv[1][0] == '-'  && (argv[1][1] == 'n')))
    {
        numeric();
    }  


/*
    char line[100];
    while (scanf("%s", line) != EOF){

    }

*/
}

