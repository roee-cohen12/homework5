#include <stdio.h>
#include <stdbool.h>

#define N 9

bool solveSudoku(int board[N][N]);
bool solve_suduko_inner(int board[N][N], int x, int y, int counter);
bool check_block(int board[N][N], int r, int c, int value);
int is_place_legal(int board[N][N], int x, int y, int value);

// Function to print the board
void printBoard(int board[N][N]) {

    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0) {
            printf("---------------------\n");
        }
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0) {
                printf("| ");
            }
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool check_block(int board[N][N], int r, int c, int value) {
    //check the value is not in its block
    //send the index check to the top right corner of the block
    int x = r - r % 3;
    int y = c - c % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[x + i][y + j] == value) {
                return true;
            }
        }
    }
    return false;
}

int is_place_legal(int board[N][N], int x, int y, int value) {
    //place a number only if the spot is empy(0)
    if (board[x][y] != 0) {
        return false;
    }
    //check the value is not in the row
    for (int i = 0; i < N; i++) {
        if (board[x][i] == value) {
            return false;
        }
    }
    //check the value is not in the col
    for (int i = 0; i < N; i++) {
        if (board[i][y] == value) {
            return false;
        }
    }
    //checks the block using auxiliary function
    if (check_block(board, x, y, value)) {
        return false;
    }
    //the place is legal for input value
    return true;
}

bool solveSudoku(int board[N][N]) {
    return solve_suduko_inner(board, 0 , 0, 0);
}

bool solve_suduko_inner(int board[N][N], int x, int y, int counter) {
    //find the first zero to start placing numbers
    while (board[x][y] != 0) {
        y++;
        if (y == N) { //end of columns
            x++;
            y = 0;
        }
        if (x == N) { //the suduko is full(not necessarily correct
            return true;
        }
    }
    for (int i = 1; i <= N; i++) {
        //check if a number can be placed in current position using helper func
        if (is_place_legal(board, x, y, i)) {
            board[x][y] = i; //place the value and continue
            bool solve = solve_suduko_inner(board, x, y, counter);
            if (solve) {
                return solve;
            }
            board[x][y] = 0; //unsuccessful placement, revert the placement
        }
    }
    //unsolvable board
    return false;
}


int main() {

    int board[N][N];

    // Read input directly into the board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    printf("Original Sudoku:\n");
    printBoard(board);

    if (solveSudoku(board)) {
        printf("Solved Sudoku:\n");
        printBoard(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}