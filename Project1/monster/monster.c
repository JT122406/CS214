#include <stdio.h>
#include <stdlib.h>

/*
int MonsterMove(playerX, playerY, monsterX, monsterY){
if((absVal(playerX - monsterX)) == absVal(playerY - monsterY)){
    //write thing to make random move here
    int r = rand() % 2;


}


}
*/
int absVal(int x){
    if(x < 0){
        x = x * -1;
        return x;
    }
    else
    return x;

}



int random1(int seed){
    srand(seed);
    int r = rand();
    int answer = 0;
    printf("%d \n", r);
    if(r > RAND_MAX/2){
        answer = 0;
        return answer;
    }
    else{
    answer = 1;
    return answer;
    }
}

int main(int argc, char *argv[]){
return EXIT_SUCCESS;


}