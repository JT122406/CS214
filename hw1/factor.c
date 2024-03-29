#include <stdio.h>
#include <stdlib.h>

int numFactors(int n){  
    int count = 0;
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            count++;
        }
    }
    return count;
}


void primeFactors1(int n){
    for (int i = 2; i <= n; i ++){
        while(n % i == 0){
            if (numFactors(i) == 0)
            {
                printf("%d ", i);
                n = n/i;
            } else {
                primeFactors1(n);
                break;
            }
        }
    }
}




int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);  //Gets Number from command line
    if(numFactors(n) == 0){
        printf("%d", n);
        printf("\n");
        return 0;
    }  //Makes sure the number has a factor if not then print out the number
    primeFactors1(n);
    printf("\n");
   
    return 0;
}
