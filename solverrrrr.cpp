// A Backtracking program  in C 
// to solve Sudoku problem 
#include <stdio.h> 
  
// UNASSIGNED is used for empty 
// cells in sudoku grid 
#define UNASSIGNED 0 
  
// N is used for the size of 
// Sudoku grid. The size will be NxN 
#define N 9 

// This function finds an entry 
// in grid that is still unassigned 
#include <stdio.h>
#define SIZE 9
//sudoku problem
int grid[9][9];
//function to print sudoku

//function to check if all cells are assigned or not
//if there is any unassigned cell
//then this function will change the values of
//row and col accordingly
int number_unassigned(int *row, int *col)
{
    int num_unassign = 0;
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            //cell is unassigned
            if(grid[i][j] == 0)
            {
                //changing the values of row and col
                *row = i;
                *col = j;
                //there is one or more unassigned cells
                num_unassign = 1;
                return num_unassign;
            }
        }
    }
    return num_unassign;
}
//function to check if we can put a
//value in a paticular cell or not
int is_safe(int n, int r, int c)
{
    int i,j;
    //checking in row
    for(i=0;i<SIZE;i++)
    {
        //there is a cell with same value
        if(grid[r][i] == n)
            return 0;
    }
    //checking column
    for(i=0;i<SIZE;i++)
    {
        //there is a cell with the value equal to i
        if(grid[i][c] == n)
            return 0;
    }
    //checking sub sudoku
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;
    for(i=row_start;i<row_start+3;i++)
    {
        for(j=col_start;j<col_start+3;j++)
        {
            if(grid[i][j]==n)
                return 0;
        }
    }
    return 1;
}
//function to solve sudoku
//using backtracking
int solve_sudoku()
{
    int row;
    int col;
    //if all cells are assigned then the sudoku is already solved
    //pass by reference because number_unassigned will change the values of row and col
    if(number_unassigned(&row, &col) == 0)
        return 1;
    int n,i;
    //number between 1 to 9
    for(i=1;i<=SIZE;i++)
    {
        //if we can assign i to the cell or not
        //the cell is sudoku[row][col]
        if(is_safe(i, row, col))
        {
            grid[row][col] = i;
            //backtracking
            if(solve_sudoku())
                return 1;
            //if we can't proceed with this solution
            //reassign the cell
            grid[row][col]=0;
        }
    }
    return 0;
}
void solver(int gen[9][9])
{
	generator(gen);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			grid[i][j]=gen[i][j];
		}
	}
    if (solve_sudoku()){
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            greed[i][j]=grid[i][j];
        }
    }
	}
    else
        printf("No solution\n");
}
