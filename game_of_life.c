#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define SIZE 100

void generate_next_step(int grid[SIZE][SIZE]);
int alive_around_point(int grid[SIZE][SIZE], int i, int j);

int main()
{
	int i, j;
	int grid[SIZE][SIZE];

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			grid[i][j] = 0;
}

void generate_next_step(int grid[SIZE][SIZE])
{
	int i, j, k, l, alive;
	int start_i, end_i, start_j, end_j;
	alive = 0;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; i++) {
			alive = alive_around_point(grid, i, j);
			if (grid[i][j] == TRUE)
				if (!(alive == 2 || alive == 3))
					grid[i][j] = FALSE;
			else
				if (alive == 3)
					grid[i][j] = TRUE;
		}
	}
}

int alive_around_point(int grid[SIZE][SIZE], int i, int j)
{
	int k, l, alive;
	alive = 0;

	for (k = i - 1; k <= i + 1; k++) {
		for (l = j - 1; l <= j + 1; l++){
			if (i < 0 || i >= SIZE || j < 0 || j >= SIZE)
				continue;
			if (k == i && l == j)
				continue;
			if (grid[k][l] == TRUE)
				alive += 1;
		}
	}
	
	return alive;
}