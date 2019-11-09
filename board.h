//Board struct
struct Board {
    int rows;
    int columns;
    int** board;
};

//Initializes the board(size and zeroes it out)
void InitBoard(Board* b);

//Returns 0 if the move is valid or 1 if the move is invalid(negative col/full col/bigger col than columns)
int CheckMove(const Board* b, int col);

//Inserts id into the lowest possible space in column col.  
void InsertInto(Board* b, int col, int id);

//Checks if the board is full. Returns 1 if it is or 0 if it isn't.
int CheckFull(const Board* b);

//Counts the score for each player id.
int CountScore(const Board* b, int id);

//Prints the current state of the board nicely formated.
void PrintBoard(const Board* b);