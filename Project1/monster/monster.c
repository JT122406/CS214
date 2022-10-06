#include <stdio.h>
#include <stdlib.h>

/*
int* MonsterMove(int playerX, int playerY, int monsterX, int monsterY){
if((absVal(playerX - monsterX)) == absVal(playerY - monsterY)){
    //write thing to make random move here
    int r = rand() % 2;


}


}
*/
int absVal(int x){
    return (x < 0) ? -x : x;
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

void printMap(int mapX, int mapY, int playerX, int playerY, int goalX, int goalY, int monsterX, int monsterY){
    for(int i = mapY - 1; i >= 0 ; i--){
        for(int j = 0; j < mapX; j++){
            if(i == playerY && j == playerX)
                printf("%c ", 'P');
            else if(i == monsterY && j == monsterX)
                printf("%c ", 'M');
            else if(i == goalY && j == goalX)
                printf("%c ", 'G');
            else{
                printf("%c ", '.');
            }
        }
        printf("\n");
    }

}

int main(int argc, char *argv[]){

    if((argc < 8) || (*argv[1] == '\0')){  //Makes sure there are command line arguments
        return 0;
    }
    int boardX = atoi(argv[1]);
    int boardY = atoi(argv[2]);
    int plrX = atoi(argv[3]);
    int plrY = atoi(argv[4]);
    int goalX = atoi(argv[5]);
    int goalY = atoi(argv[6]);
    int monX = atoi(argv[7]);
    int monY = atoi(argv[8]);




printMap(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY);
return EXIT_SUCCESS;


char current;
    while (scanf("%c", current)!= EOF) 
    {
        /* code */
    }
}