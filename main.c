#include<stdio.h>
#include"board.h"
#include<stdlib.h>
#include"player.h"
#include"player_random.h"

extern int player_random(Board* b);
extern int player(Board* b);

int (*player1)(Board* b) = player;
int (*player2)(Board* b) = player_random;

int main(){

    Board* board;
    board = (Board*) malloc(sizeof(Board));
    InitBoard(board, 10, 10);

    printf("Hello and welcome to the advanced connect4 game!\n");
    printf("You know the rules, you know the game, you (probably) have a working solution.\n");
    printf("Let the game begin!\n");
    

    while(!CheckFull(board)){
        int move_a = player1(board);
        int move_b = player2(board);

        if(CheckMove(board, move_a)){
            printf("Player 1 Loses. Player 2 wins!(invalid move)\n");
            PrintBoard(board);
            break;
        }
        if(CheckMove(board, move_a)){
            printf("Player 1 Loses. Player 2 wins!(invalid move)\n");
            PrintBoard(board);
            break;
        }

        InsertInto(board, move_a, 1);
        PrintBoard(board);
        InsertInto(board, move_b, 2);
        PrintBoard(board);
    }

    int score_a = CountScore(board, 1);
    int score_b = CountScore(board, 2);

    printf("Player 1: %d , Player 2: %d\n", score_a, score_b);
    if(score_a > score_b){
        printf("Player 1 wins!\n");
    }else if(score_a < score_b){
        printf("Player 2 wins!\n");
    }else{
        printf("It's a tie!\n");
    }

    DestroyBoard(board);
    return 0;
}