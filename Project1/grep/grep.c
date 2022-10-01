#include <stdio.h>

int main(int argc, char *argv[]) {
    if((argc < 2) || (*argv[1] == '\0')){  //Makes sure there is a string to search for
        return 0;
    }
    char* search = argv[1]; //The string to search for
    int string = 0;
    for(int i = 0; argv[1][i] != '\0'; i++){
        search[i] = argv[1][i];
        string++;
    }


    int boolean = 0;
    char line[100];

    while (scanf("%s", line) != EOF) { //Reads in the string to search




        for (int i = 0; i < line[i] != '\0'; i++) {
            if (line[i] == search[0]){  //First Character Matches the looking string
                for (int j = 1; j < string; j++) {  //Checks the rest of the string
                    i++;
                    if (search[j] != line[i]){
                        boolean = 1;
                        break;
                    } else if(search[0] == line[i]){
                        i--;
                        break;
                    }
                }
                if (boolean == 0) {
                    //printf("%s", line);
                    //printf("%s", "\n");
                    break;
                }
            }
        }

        if (boolean == 0) {
            for (int i = 0; i < line[i] != '\0'; i++){
                printf("%c", line[i]);
            }
            printf("%s", " ");
        }

        boolean = 0;

        //printf("%s", "\n");


    }
    return 0;
}