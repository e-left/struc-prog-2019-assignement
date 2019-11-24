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

    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            b->board[i][j] = 0;
        }
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

    if(col >= b->columns){
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

    //checking for sequential no's in a row
    for(int i = 0; i< b->rows; i++){
        for(int j = 0; j< b->columns; j++){
            if(b->board[i][j] == id && j <= b->columns - 2){
                tempscore = 1;
                j++;

                while(j < b->columns && b->board[i][j] == id){
                    tempscore++;
                    j++;
                }

                if(tempscore == 1){
                    tempscore = 0;
                }
            }

            score += tempscore;
            tempscore = 0;

        }

    }



    //checking for vertical numbers in a row
    for(int j = 0; j< b->columns; j++){
        for(int i = 0; i< b->rows; i++){
            if(b->board[i][j] == id && i <= b->rows - 2){
                tempscore = 1;
                i++;

                while(i < b->rows && b->board[i][j] == id){
                    tempscore++;
                    i++;
                }

                if(tempscore == 1){
                    tempscore = 0;
                }
            }

            score += tempscore;
            tempscore = 0;

        }

    }

   //diagonaly from top-left to bottom-right

    for(int i = 0; i < b->rows; i++){
       //int tempi = i;
       //int tempj = 0;
        for(int tempi = i, tempj = 0; (tempi < b->rows) && (tempj < b->columns); tempi++, tempj++){

            if(b->board[tempi][tempj] == id && tempi <= b->rows - 2 && tempj <= b->columns - 2){
                tempscore = 1;
                tempi++;
                tempj++;
                while(tempi < b->rows && tempj < b->columns && b->board[tempi][tempj] == id){
                   tempscore++;
                   tempi++;
                   tempj++;
                }

                if(tempscore == 1){
                    tempscore = 0;
                }
                //printf("%d\n", tempscore);
                score += tempscore;
                tempscore = 0;

            }

        }
    }


    for(int j = 1; j < b->columns; j++){


        for(int tempi = 0, tempj = j; tempi < b->rows && tempj < b->columns; tempi++, tempj++){
            if(b->board[tempi][tempj] == id && tempi <= b->rows - 2 && tempj <= b->columns - 2){
                tempscore = 1;
                tempi++;
                tempj++;
                while(tempi < b->rows && tempj < b->columns && b->board[tempi][tempj] == id){
                    tempscore++;
                    tempi++;
                    tempj++;
                }

                if(tempscore == 1){
                    tempscore = 0;
                }else{
                    //tempscore--;
                }
                score += tempscore;
                tempscore = 0;

            }
        }

    }

    //diagonaly from top right to bottom left
    for(int i = 0; i < b->rows; i++){
       //int tempi = i;
       //int tempj = 0;
        for(int tempi = i, tempj = b->columns - 1; (tempi < b->rows) && (tempj >= 0); tempi++, tempj--){

            if(b->board[tempi][tempj] == id && tempi <= b->rows - 2 && tempj >= 1){
                tempscore = 1;
                tempi++;
                tempj--;
                while(tempi < b->rows && tempj >= 0 && b->board[tempi][tempj] == id){
                   tempscore++;
                   tempi++;
                   tempj--;
                }

                if(tempscore == 1){
                    tempscore = 0;
                }
                //printf("%d\n", tempscore);
                score += tempscore;
                tempscore = 0;

            }

        }
    }


    for(int j = 0; j < b->columns - 1; j++){


        for(int tempi = 0, tempj = j; tempi < b->rows && tempj > 0; tempi++, tempj--){
            if(b->board[tempi][tempj] == id && tempi <= b->rows - 2 && tempj >= 1){
                tempscore = 1;
                tempi++;
                tempj--;
                while(tempi < b->rows && tempj >= 0 && b->board[tempi][tempj] == id){
                    tempscore++;
                    tempi++;
                    tempj--;
                }

                if(tempscore == 1){
                    tempscore = 0;
                }else{
                    //tempscore--;
                }
                score += tempscore;
                tempscore = 0;

            }
        }

    }


    //TODO implement other countings


    return score;
}

//Prints the current state of the board nicely formated.
//Assuming that no more than 9 players are playing the game
void PrintBoard(const Board* b){
    putchar('\n');
    for(int i = 0; i< 2*(b->columns) + 1; i++){
        if(i % 2 == 0){
            printf("+");
        }else{
            printf("---");
        }
    }
    printf("\n");

    for(int i = 0; i< b->rows; i++){
        for(int j = 0; j< b->columns; j++){
            if(b->board[i][j] == 0)
                printf("|   ");
            else
                printf("| %d ", b->board[i][j]);
        }
        printf("|\n");

        for(int i = 0; i< 2*(b->columns) + 1; i++){
            if(i % 2 == 0){
                printf("+");
            }else{
                printf("---");
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
