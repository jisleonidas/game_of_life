#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define SIZE 100

void display_grid(int grid[SIZE][SIZE]);
void generate_next_step(int grid[SIZE][SIZE]);
int alive_around_point(int grid[SIZE][SIZE], int i, int j);

int main()
{
	int i, j;
	int grid[SIZE][SIZE];

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			grid[i][j] = 0;

	display_grid(grid);
}

void display_grid(int grid[SIZE][SIZE])
{
	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (grid[i][j] == TRUE)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}
}

void generate_next_step(int grid[SIZE][SIZE])
{
	int i, j, cur_alive;
	int alive[SIZE][SIZE];

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			alive[i][j] = alive_around_point(grid, i, j);
		}
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			cur_alive = alive[i][j];
			if (grid[i][j] == TRUE) {
				if (!(cur_alive == 2 || cur_alive == 3))
					grid[i][j] = FALSE;
			}
			else {
				if (cur_alive == 3)
					grid[i][j] = TRUE;
			}
		}
	}
}

int alive_around_point(int grid[SIZE][SIZE], int i, int j)
{
	int k, l, alive;
	alive = 0;

	for (k = i - 1; k <= i + 1; k++) {
		for (l = j - 1; l <= j + 1; l++) {
			if (0 <= k < SIZE && 0 <= l < SIZE) {
				if (k == i && l == j)
					continue;
				if (grid[k][l] == TRUE)
					alive += 1;
			}
		}
	}

	return alive;
}