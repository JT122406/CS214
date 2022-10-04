#include <stdio.h>

int main(int argc, char *argv[]) {
    int caseSensetive = 0;

    if((argc < 2) || (*argv[1] == '\0')){  //Makes sure there is a string to search for
        return 0;
    }
    char* search = argv[1]; //The string to search for and if we are case sensetive
    if (argv[1][0] == '-'  && argv[1][1] == 'i'){
            caseSensetive = 1;
            search = argv[2];
    } else {
        search = argv[1];
    }



    int boolean = 0;
    char* line;
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
                    printf("%s", line);
                    printf("%c", '\n');
                    break;
                }
            }
        }

        if (boolean == 0) {
            for (int i = 0; i < line[i] != '\0'; i++){
                printf("%c", line[i]);
            }
            printf("%c", ' ');
        }
        boolean = 0;
        printf("%c", '\n');

        for (int k = 0; k < sizeof(line); k++)
        {
            line[k] = '\0';
        }
        
    }
    return 0;
}