#include<stdio.h>
#include"board.h"
#include<stdlib.h>

int main(){

    Board* board;
    board = (Board*) malloc(sizeof(Board));
    printf("%d",InitBoard(board, 5, 6));

    return 0;
}