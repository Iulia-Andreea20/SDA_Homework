#include <stdio.h>
#define EMPTY 0
#define GRIND_SIZE 9


int find_empty_locations(int grid[GRIND_SIZE][GRIND_SIZE],int *row, int *column);

int is_safe(int grid[GRIND_SIZE][GRIND_SIZE], int row, int column, int nr);


int solve_sudoku(int grid[GRIND_SIZE][GRIND_SIZE])
{
	int row, column;


	if (!find_empty_locations(grid, &row, &column))
    {
        return 1; 
    }
		
	for (int nr = 1; nr <= 9; nr++)
	{
		
		if (is_safe(grid, row, column, nr))
		{
			
			grid[row][column] = nr;
			if (solve_sudoku(grid))
            {
                return 1;
            }

			grid[row][column] = EMPTY;
		}
	}

	return 0;
}

int find_empty_locations(int grid[GRIND_SIZE][GRIND_SIZE], int *row, int *column)
{
	for ((*row) = 0; (*row) < GRIND_SIZE; (*row)++)
    {
        for ((*column) = 0; (*column) < GRIND_SIZE; (*column)++)
        {
            if (grid[*row][*column] == EMPTY)
            {
                return 1;
            }		
        }		
    }

	return 0;
}


int used_in_row(int grid[GRIND_SIZE][GRIND_SIZE], int row, int nr)
{
	for (int column = 0; column < GRIND_SIZE; column++)
    {
        if (grid[row][column] == nr)
        {
            return 1;
        }
    }
	
    return 0;
}

int used_in_column(int grid[GRIND_SIZE][GRIND_SIZE], int column, int nr)
{
	for (int row = 0; row < GRIND_SIZE; row++)
    {
        if (grid[row][column] == nr)
        {
            return 1;
        }
    }
		
	return 0;
}

int used_in_box(int grid[GRIND_SIZE][GRIND_SIZE], int box_start_row, int box_start_column, int nr)
{
	for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (grid[row + box_start_row][column + box_start_column] == nr)
            {
                return 1;
            }
        }
			
    }
		
	return 0;
}


int is_safe(int grid[GRIND_SIZE][GRIND_SIZE], int row, int column, int nr)
{
	
	return !used_in_row(grid, row, nr) && !used_in_column(grid, column, nr) && !used_in_box(grid, row - row % 3,column - column % 3, nr) && grid[row][column] == EMPTY;

}

void display_grind(int grid[GRIND_SIZE][GRIND_SIZE])
{
	for (int row = 0; row < GRIND_SIZE; row++) 
    {
		for (int column = 0; column < GRIND_SIZE; column++)
        {
            printf("%2d", grid[row][column]);
        }
		printf("\n");
	}
}


int main()
{

// int grid[GRIND_SIZE][GRIND_SIZE] = { { 1, 2, 7, 5, 1, 6, 4, 9, 8 },
// 					                 { 4, 0, 0, 2, 8, 7, 0, 0, 5 },
// 					                 { 0, 0, 0, 0, 4, 0, 0, 0, 0 },
// 					                 { 0, 0, 6, 0, 0, 0, 5, 0, 0 },
// 					                 { 0, 0, 0, 0, 5, 0, 0, 0, 0 },
// 					                 { 7, 0, 0, 0, 3, 0, 0, 0, 1 },
// 					                 { 8, 0, 2, 0, 0, 0, 9, 0, 3 },
// 					                 { 0, 1, 3, 0, 0, 0, 8, 4, 0 },
// 					                 { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

int grid[GRIND_SIZE][GRIND_SIZE] = { { 3, 2, 7, 5, 1, 6, 4, 9, 8 },
					                 { 4, 0, 0, 2, 8, 7, 0, 0, 5 },
					                 { 0, 0, 0, 0, 4, 0, 0, 0, 0 },
					                 { 0, 0, 6, 0, 0, 0, 5, 0, 0 },
					                 { 0, 0, 0, 0, 5, 0, 0, 0, 0 },
					                 { 7, 0, 0, 0, 3, 0, 0, 0, 1 },
					                 { 8, 0, 2, 0, 0, 0, 9, 0, 3 },
					                 { 0, 1, 3, 0, 0, 0, 8, 4, 0 },
					                 { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };


    printf(" Rezolvarea este:\n\n");
	if (solve_sudoku(grid) == 1)
    {
        display_grind(grid);
    }
	else
    {
        printf("Nu exista solutii!\n");
    }


	return 0;
}
