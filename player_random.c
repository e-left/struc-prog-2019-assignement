#include<stdlib.h>

#include"board.h"

extern int random_player(const Board* b){
    int moves[10];
    int counter = 0;
    for(int i = 0; i < b->columns; i++){
        if(b->board[0][i] == 0){
            moves[counter++] = i;
        }
    }

    int move = rand() % (counter + 1);

    return moves[move];
}
