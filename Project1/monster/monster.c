#include <stdio.h>
#include <stdlib.h>

struct PlayerMovement{
    int layerX;
    int layerY;
    int moveValid;
};

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


void MonsterMove(int playerX, int playerY, int goalX, int goalY, int monsterX, int monsterY){
int newCords [2] = {monsterX, monsterY};
char direction = 'A';
if((absVal(playerX - monsterX)) == absVal(playerY - monsterY)){
    //write thing to make random move here
    int r = random1(playerX + monsterY);
    if(r == 1){
        //move horizontal
        if(playerX - monsterX < 0){
            direction = 'W';
            newCords[0] = monsterX - 1;
        }
        else{
            direction = 'E';
            newCords[0] = monsterX + 1;
        }
    }
    else{
        //move vertical
        if(playerY - monsterY < 0){
            direction = 'S';
            newCords[1] = monsterX - 1;
        }
        else{
            direction = 'N';
            newCords[1] = monsterX + 1;
        }
    }


}

else if((absVal(playerX - monsterX)) > absVal(playerY - monsterY)){

        if(playerX - monsterX < 0){
            direction = 'W';
            newCords[0] = monsterX - 1;
        }
        else{
            direction = 'E';
            newCords[0] = monsterX + 1;
        }

}
else if((absVal(playerX - monsterX)) < absVal(playerY - monsterY)){
        if(playerY - monsterY < 0){
            direction = 'S';
            newCords[1] = monsterX - 1;
        }
        else{
            direction = 'N';
            newCords[1] = monsterX + 1;
        }



}

if(!(newCords[0] == goalX && newCords[1] == goalY)){
printf("monster moves ");
printf("%c \n", direction);
monsterX = newCords[0];
monsterY = newCords[1];

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

struct PlayerMovement PlayerMove(int mapX, int mapY, int playerX, int playerY, int goalX, int goalY, int monsterX, int monsterY, char direction){
struct PlayerMovement newCords;
newCords.layerX = playerX;
newCords.layerY = playerY;
newCords.moveValid = 0;

if(direction == 'N'){
    newCords.layerY = playerY + 1;
} 
if(direction == 'S'){
    newCords.layerY = playerY - 1;
}
if(direction == 'E'){
    newCords.layerX = playerX + 1;
}
if(direction == 'W'){
    newCords.layerX = playerX - 1;
}
if(newCords.layerX >= mapX || newCords.layerX < 0 || newCords.layerY >= mapY || newCords.layerY < 0){
    printf("invalid move \n");
    newCords.moveValid = 0;
    newCords.layerX = playerX;
    newCords.layerY = playerY;
    return newCords;
}
else{
    //validMove = 1;
    //playerX = newCords[0];
    //playerY = newCords[1];
    newCords.moveValid = 1;

    return newCords;
}



}



int main(int argc, char *argv[]){
    int gameEnd = 0;
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


//return EXIT_SUCCESS;
struct PlayerMovement isValidMove;

char current;
    while (scanf("%c", &current)!= EOF) 
    {
        if(current == 'N' || current == 'S' || current == 'E' || current == 'W'){
            isValidMove = PlayerMove(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY, current);

        }
        if(isValidMove.moveValid){
            plrX = isValidMove.layerX;
            plrY = isValidMove.layerY;
            printMap(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY);
            //printf("this ran \n");
            isValidMove.moveValid = 0;
        }
    }
    return EXIT_SUCCESS;
}