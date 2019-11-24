#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>

#include"board.h"

#include"player.h"
#include"player_random.h"

extern int player_random(const Board* b);
extern int player(const Board* b);

//int (*player1)(const Board* b) = player;
int (*player2)(const Board* b) = random_player;
int (*player1)(const Board* b) = random_player;

int main(){
    // Must be called one time
    srand(time(0));

    Board* board;
    board = (Board*) malloc(sizeof(Board));
    int width, height;
    float delay = 0;
    int moves = 0;


    printf("Hello and welcome to the advanced connect4 game!\n");
    printf("You know the rules, you know the game, you (probably) have a working solution.\n");
    printf("Input the dimensions(rows x columns): ");
    scanf("%d %d", &height, &width);
    printf("Input the delay in seconds between plays (0 if you do not want delay and -1 if you want to press enter to continue): ");
    scanf("%f", &delay);
    printf("Let the game begin!\n");
    InitBoard(board, height, width);

    while(!CheckFull(board)){
        if(delay < 0){
            printf("Press enter to continue...");
            getchar();
        }
        else usleep(delay * 1000000);

        printf("\n-------------- Move #%d --------------\n", moves++);
        int move_a = player1(board);
        printf("Player 1 chooses %d\n", move_a);

        if(CheckMove(board, move_a)){
            printf("Player 1 Loses. Player 2 wins!(invalid move)\n");
            PrintBoard(board);
            exit(0);
        }
        InsertInto(board, move_a, 1);
        PrintBoard(board);
        int move_b = player2(board);
        printf("Player 2 chooses %d\n", move_b);
        if(CheckMove(board, move_b)){
            printf("Player 2 Loses. Player 1 wins!(invalid move)\n");
            PrintBoard(board);
            exit(0);
        }
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
