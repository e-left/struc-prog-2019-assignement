#include<stdio.h>
#include"board.h"
#include<stdlib.h>

int main(){

    Board* board;
    board = (Board*) malloc(sizeof(Board));
    //printf("%d",InitBoard(board, 5, 6));
    InitBoard(board, 10,10);
    PrintBoard(board);
    InsertInto(board, 1, 3);
    InsertInto(board, 1, 2);
    InsertInto(board, 0, 2);
    InsertInto(board, 2, 2);
    InsertInto(board, 2, 3);
    InsertInto(board, 2, 2);
    InsertInto(board, 0, 2);
    InsertInto(board, 0, 2);
    InsertInto(board, 0, 2);
    InsertInto(board, 1, 3);
    //InsertInto(board, 8, 2);
    //InsertInto(board, 9, 2);
    //InsertInto(board, 1, 3);
    //InsertInto(board, 1, 2);
    
    InsertInto(board, 8, 3);
    InsertInto(board, 8, 3);
    InsertInto(board, 8, 3);
    InsertInto(board, 8, 3);
    InsertInto(board, 8, 3);
    InsertInto(board, 8, 3);
    InsertInto(board, 8, 3);
    InsertInto(board, 8, 3);
    InsertInto(board, 9, 3);
    InsertInto(board, 9, 3);
    InsertInto(board, 9, 3);
    InsertInto(board, 9, 3);
    InsertInto(board, 9, 3);
    InsertInto(board, 9, 3);
    InsertInto(board, 9, 3);
    InsertInto(board, 9, 3);
    InsertInto(board, 8, 6);
    InsertInto(board, 8, 5);
    InsertInto(board, 9, 5);

    //InsertInto(board, 3, 2);
    //InsertInto(board, 0, 2);
    //InsertInto(board, 0, 2);
    //InsertInto(board, 0, 2);
    //InsertInto(board, 0, 2);
    //InsertInto(board, 0, 2);
    //InsertInto(board, 9, 2);
    //InsertInto(board, 8, 2);
    //InsertInto(board, 8, 2);
    //InsertInto(board, 0, 2);
    //InsertInto(board, 0, 2);
    //InsertInto(board, 0, 2);
    //InsertInto(board, 3, 2);
    //InsertInto(board, 3, 2);
    //InsertInto(board, 4, 2);
    //InsertInto(board, 4, 2);
    InsertInto(board, 9, 6);

    PrintBoard(board);
    printf("%d\n", CountScore(board, 6));


    return 0;
}