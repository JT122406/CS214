#include <stdio.h>
#include <stdlib.h>

/*
int MonsterMove(int playerX, int playerY, int monsterX, int monsterY){
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

void printMap(int playerX, int playerY, int monsterX, int monsterY, int goalX, int goalY, int mapX, int mapY){
    for(int i = mapX - 1; i >= 0 ; i--){
        for(int j = 0; j < mapX; j++){
            if(i == playerX && j == playerY)
                printf("%c ", 'P');
            else if(i == monsterX && j == monsterY)
                printf("%c ", 'M');
            else if(i == goalX && j == goalY)
                printf("%c ", 'G');
            else{
                printf("%c ", '.');
            }
        }
        printf("\n");
    }

}

int main(int argc, char *argv[]){
printMap(0, 0, 3, 4, 1, 1, 5, 5);
return EXIT_SUCCESS;


}