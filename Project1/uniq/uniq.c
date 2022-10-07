#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char current [100][100]; //current line
    int apperiences[100]; //array of apperiences
    int i = 0;
    while(scanf("%s", current[i]) != EOF) {
        if (i == 0)
        {
            apperiences[0] = 1;
            i++;
            continue;
        }
        if (apperiences[i] == 0)
            apperiences[i] = 1;
        
        
        
            if (strcmp(current[i], current[i - 1]) == 0)  //string matches string before
            {
                apperiences[i-1]++;
                apperiences[i] = 0;
            }
            else
            {
                i++;
            }
            
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d ", apperiences[j]);
        printf("%s", current[j]);
        printf("%c", '\n'); 
    }
}