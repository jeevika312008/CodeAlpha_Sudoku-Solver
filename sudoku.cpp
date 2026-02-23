#include <iostream>
using namespace std;

#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if number is safe in row
bool checkRow(int grid[N][N], int row, int num)
{
    for(int col = 0; col < N; col++)
    {
        if(grid[row][col] == num)
            return false;
    }
    return true;
}

// Check if number is safe in column
bool checkCol(int grid[N][N], int col, int num)
{
    for(int row = 0; row < N; row++)
    {
        if(grid[row][col] == num)
            return false;
    }
    return true;
}

// Check 3x3 box
bool checkBox(int grid[N][N], int startRow, int startCol, int num)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

// Check if safe to place number
bool isSafe(int grid[N][N], int row, int col, int num)
{
    return checkRow(grid, row, num) &&
           checkCol(grid, col, num) &&
           checkBox(grid, row - row % 3, col - col % 3, num);
}

// Backtracking function
bool solveSudoku(int grid[N][N])
{
    for(int row = 0; row < N; row++)
    {
        for(int col = 0; col < N; col++)
        {
            if(grid[row][col] == 0)
            {
                for(int num = 1; num <= 9; num++)
                {
                    if(isSafe(grid, row, col, num))
                    {
                        grid[row][col] = num;

                        if(solveSudoku(grid))
                            return true;

                        grid[row][col] = 0; // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int grid[N][N];

    cout << "Enter Sudoku grid (use 0 for empty cells):\n";

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    if(solveSudoku(grid))
    {
        cout << "\nSolved Sudoku:\n";
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists.";
    }

    return 0;
}
