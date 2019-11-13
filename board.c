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
    if(col < 0){
        return 1;
    }

    if(col > b->columns){
        return 1;
    }

    if(b->board[0][col] != 0){
        return 1;
    }

    return 0;
}

//Inserts id into the lowest possible space in column col.  
void InsertInto(Board* b, int col, int id){
    for(int i = (b->rows)-1; i >= 0; i--){
        if(b->board[i][col] == 0){
            b->board[i][col] = id;
            return;
        }
    }
}

//Checks if the board is full. Returns 1 if it is or 0 if it isn't.
int CheckFull(const Board* b){
    for(int i = 0; i< b->columns; i++){
        if(b->board[0][i] == 0){
            return 0;
        }
    }

    return 1;
}

//Counts the score for each player id.
int CountScore(const Board* b, int id){
    int score = 0;
    int tempscore = 0;
    int count = 0;
    
    //checking for sequential no's in a row
    for(int i = 0; i< b->rows; i++){
        for(int j = 0; j< b->columns; j++){
            if(b->board[i][j] == id){
                tempscore++;
            }
        }
        
        if(tempscore > 2){
            score += tempscore;
        }

        tempscore = 0;
    }

    //TODO implement other countings

}

//Prints the current state of the board nicely formated.
//Assuming that no more than 9 players are playing the game
void PrintBoard(const Board* b){
    for(int i = 0; i< 2*(b->columns) + 1; i++){
        if(i % 2 == 0){
            printf("+");
        }else{
            printf("-");
        }
    }
    printf("\n");


    for(int i = 0; i< b->rows; i++){
        for(int j = 0; j< b->columns; j++){
            printf("|%d", b->board[i][j]);
        }
        printf("|\n");

        for(int i = 0; i< 2*(b->columns) + 1; i++){
            if(i % 2 == 0){
                printf("+");
            }else{
                printf("-");
            }
        }
    
        printf("\n");

    }


}

//Free the memory needed for the board
void DestroyBoard(Board* b){
    for(int i = 0; i< b->rows; i++){
        free(b->board[i]);
    }
    free(b->board);
}