#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//factor 32 prints 2 16 times which is not right
int factors(int n){  //returns number of factors not including 1 and itself
    int count = 0;
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    if(factors(n) == 0){
        printf("%d", n);
        printf("\n");
        return 0;
    }
    int isPrime;
    for (int i = 2; i < n; i++){
        if(n % i == 0){
            isPrime = 1;
            for (int j = 2; j <= i/2; j++){
                if(i%j == 0){
                    isPrime = 0;
                    break;
                }
            }
            if (isPrime == 1){
                if((n / i) > 1){  //more than one of that factor
                    for (int k = 0; k < (log(n)/ log(i)); k++){
                        printf("%d" , i);
                        printf("%c", ' ');
                    }
                } else{
                    printf("%d" , i);
                    printf("%c", ' ');
                }
            }
        }
    }
    printf("\n");
    return 0;
}
