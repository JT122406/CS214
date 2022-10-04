#include <stdio.h>
#include <ctype.h>

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


if (caseSensetive == 0)  //case do not matter
{
    int boolean = 0;
    char line[100];
    while (scanf("%s", line) != EOF) { //Reads in the string to search
        for (int i = 0; i < line[i] != '\0'; i++) {
            if (tolower(line[i]) == tolower(search[0])){  //First Character Matches the looking string
            int j = 1;
            do
            {
                i++;
                    if (tolower(search[j]) != tolower(line[i])){
                        boolean = 1;
                        break;
                    } else if(tolower(search[0]) == tolower(line[i])){
                        i--;
                        break;
                    }
                    j++;
            } while (search[i] != '\0');
                if (boolean == 0) {
                    printf("%s", line);
                    printf("%c", '\n');
                    break;
                }
                
            }
        }
        boolean = 0;
    }
} else { //case sensetive 
int boolean = 0;
    char line[100];
    while (scanf("%s", line) != EOF) { //Reads in the string to search
        for (int i = 0; i < line[i] != '\0'; i++) {
            if (line[i] == search[0]){  //First Character Matches the looking string
            int j = 1;
            do
            {
                i++;
                    if (search[j] != line[i]){
                        boolean = 1;
                        break;
                    } else if(search[0] == line[i]){
                        i--;
                        break;
                    }
                    j++;
            } while (search[i] != '\0');
                if (boolean == 0) {
                    printf("%s", line);
                    printf("%c", '\n');
                    break;
                }
                
            }
        }
        boolean = 0;
    }
}
    return 0;
}