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

        for (int j = 0; j < i; j++)
        {
            if (strcmp(current[i], current[j]) == 0)
            {
                if (apperiences[j] == 0)
                {
                apperiences[j] = 0;
                }
                apperiences[j]++;
                break;
            }
            else if (j == i - 1)
            {
                i++;
                break;
            }
        }
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d ", apperiences[j]);
        printf("%s", current[j]);
        printf("%c", '\n'); 
    }
}