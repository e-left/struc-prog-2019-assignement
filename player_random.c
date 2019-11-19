#include"board.h"
#include<stdlib.h>
#include<time.h>

extern int random_player(Board* b){
    int moves[10];
    int counter = 0;
    for(int i = 0; i < b->columns; i++){
        if(b->board[0][i] == 0){
            moves[counter++] = i;
        }
    }
    srand(time(0));
    int move = rand() % (counter + 1);

    
    return moves[move];
}