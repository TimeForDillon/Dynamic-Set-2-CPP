/*******************************************************************************
* AUTHOR        : Dillon Welsh, Jared Sobol
* LAB 3         : Dynamic Set
* CLASS         : CS8
* SECTION       : 33776
* DUE DATE      : 03/27/2021
*******************************************************************************/

#include <iostream>

using namespace std;

const int SIZE = 5;

/*******************************************************************************
 * isFree
 *      This function returns true if the board is free and false if the board
 *      is not free
 ******************************************************************************/
bool isFree(int board[SIZE][SIZE],      // IN - the chess board
            int row,                    // IN - the row of the chess board
            int column);                // IN - the column of the chess board

/*******************************************************************************
 * printBoard
 *      This function prints the board out
 ******************************************************************************/
void printBoard(int board[SIZE][SIZE]); // IN - the chess board

/*******************************************************************************
 * checkStack
 *      This function checks the stack for successful queen placements
 ******************************************************************************/
bool checkStack(int board[SIZE][SIZE],  // IN - the chess board
                int col);               // IN - the column of the chess board

/*******************************************************************************
 * solveNQueens
 *      This function will pring out all solutions for N queens
 ******************************************************************************/
void solveNQueens(int N);               // IN - number of queens

int main()
{
    int N = 0;      // IN - number of queens
    std::cout << "Enter the number of queens: ";
    std::cin >> N;
    std::cout << "\n";
    std::cout << "SOLUTIONS: ";
    std::cout << "\n";
    solveNQueens(N);
    return 0;
}

/*******************************************************************************
 * isFree
 *      This function returns true if the board is free and false if the board
 *      is not free
 * _____________________________________________________________________________
 * INPUT:
 *      int board[SIZE][SIZE],
 *      int row,
 *      int column
 * OUTPUT:
 *      bool: true if free
 ******************************************************************************/

bool isFree(int board[SIZE][SIZE],      // IN - the chess board
            int row,                    // IN - the row of the chess board
            int column)                 // IN - the column of the chess board
{
    int i, j;

    // PROCESSING - Checks Row
    for (i = 0; i < column; i++)
    {
        if (board[row][i]) {return false;}
    }

    // PROCESSING - Checks Column
    for (i = row, j = column; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j]) {return false;}
    }

    // PROCESSING - Checks Diagonal
    for (i = row, j = column; j >= 0 && i < SIZE; i++, j--)
    {
        if (board[i][j]) {return false;}
    }

    return true;
}

/*******************************************************************************
 * printBoard
 *      This function prints the board out
 * _____________________________________________________________________________
 * INPUT:
 *      int board[SIZE][SIZE]
 * OUTPUT:
 *      none
 ******************************************************************************/

void printBoard(int board[SIZE][SIZE]) // IN - the chess board
{
    // PROCESSING - outputs the board
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // PROCESSING - 1 is queen else empty
            if(board[i][j] == 1)
            {
               std::cout << "\u265B" << " ";
            } else {
               std::cout << "\u25A1" << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

/*******************************************************************************
 * checkStack
 *      This function checks the stack for successful queen placements
 * _____________________________________________________________________________
 * INPUT:
 *      int board[SIZE][SIZE]
 * OUTPUT:
 *      none
 ******************************************************************************/

bool checkStack(int board[SIZE][SIZE],  // IN - the chess board
                int col)                // IN - the column of the chess board
{
    // PROCESSING -  base case: If all queens are placed then return true
    if (col == SIZE)
    {
        printBoard(board);
        return true;
    }

    bool success = false;
    for (int i = 0; i < SIZE; i++)
    {
        if (isFree(board, i, col) )
        {
            board[i][col] = 1;

            // PROCESSING - recursive call
            success = checkStack(board, col + 1) || success;

             // PROCESSING - BACKTRACK to the stack
            board[i][col] = 0;
        }
    }

    // PROCESSING - If no empty locations
    return success;
}

/*******************************************************************************
 * solveNQueens
 *      This function will pring out all solutions for N queens
 * _____________________________________________________________________________
 * INPUT:
 *      int board[SIZE][SIZE]
 * OUTPUT:
 *      none
 ******************************************************************************/

void solveNQueens(int N)               // IN - number of queens
{
    std::cout << endl << "TESTING FOR " << N << " QUEENS" << endl << endl;

    int board[SIZE][SIZE] = { { 0, 0, 0, 0 },
                            { 0, 0, 0, 0 },
                            { 0, 0, 0, 0 },
                            { 0, 0, 0, 0 } };

    if (checkStack(board, 0) == false)
    {
        std::cout <<"Solution does not exist";
        return ;
    }

    return ;
}
