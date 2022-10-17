#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void printdirect(DIR *dr){
    struct dirent *de;

}

int main(){
    printf("%c\n", '.');
    printdirect(opendir(".")); 
    return 0;
}