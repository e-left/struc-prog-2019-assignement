#include"board.h"
#include<stdio.h>
#include<stdlib.h>

//Initializes the board(size and zeroes it out)
int InitBoard(Board* b, int r, int c){
    b->rows = r;
    b->columns = c;
    
    b->board = (int**) malloc(r * sizeof(int*));   

    if(b->board == NULL){
        printf("Error allocating memory for the board!");
        return -1;
    }
    
    for(int i = 0; i < r; i++){
        b->board[i] = (int*) malloc(c * sizeof(int));
    }


    for(int i = 0; i < r; i++){
        if (b->board[i] == NULL){
            printf("Error allocating memory for the board!");
            return -1;
        }
    }

    return 0;

}

//Returns 0 if the move is valid or 1 if the move is invalid(negative col/full col/bigger col than columns)
int CheckMove(const Board* b, int col){

}

//Inserts id into the lowest possible space in column col.  
void InsertInto(Board* b, int col, int id){

}

//Checks if the board is full. Returns 1 if it is or 0 if it isn't.
int CheckFull(const Board* b){

}

//Counts the score for each player id.
int CountScore(const Board* b, int id){

}

//Prints the current state of the board nicely formated.
void PrintBoard(const Board* b){

}

//Free the memory needed for the board
void DestroyBoard(Board* b);