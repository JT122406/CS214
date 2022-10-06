#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
    char line[100];

if (caseSensetive == 0)  //case do not matter
{
    while (scanf(" %100[0-9a-zA-Z ]", line) != EOF) { //Reads in the string to search
        for (int i = 0; line[i] != '\0'; i++) {
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
            } while (i < strlen(search) && i < strlen(line));  //prevent possible null pointer
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
    while (scanf(" %100[0-9a-zA-Z ]", line) != EOF) { //Reads in the string to search
        for (int i = 0; line[i] != '\0'; i++) {
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
            } while (i < strlen(search) && i < strlen(line));  //prevent possible null pointer
                if (boolean == 0) {
                    printf("%s", line);
                    printf("%c", '\n');
                    break;
                } 
            }
        }
        boolean = 0;
    }
    return 0;
}