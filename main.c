#include<stdio.h>
#include"board.h"
#include<stdlib.h>

int main(){

    Board* board;
    board = (Board*) malloc(sizeof(Board));
    //printf("%d",InitBoard(board, 5, 6));
    InitBoard(board, 10,10);
    PrintBoard(board);
    InsertInto(board, 5, 2);
    PrintBoard(board);


    return 0;
}