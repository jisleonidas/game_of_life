#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define SIZE 50
#define PATTERN_SIZE 5

void display_grid(int grid[SIZE][SIZE]);
void generate_next_step(int grid[SIZE][SIZE]);
int alive_around_point(int grid[SIZE][SIZE], int i, int j);
int input_pattern(int pattern[PATTERN_SIZE][PATTERN_SIZE]);
void skipgarb();

int main()
{
	int i, j;
	int pattern[PATTERN_SIZE][PATTERN_SIZE];
	int grid[SIZE][SIZE];

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			grid[i][j] = 0;

	printf("Enter initial 5x5 pattern:\n");

	if (!input_pattern(pattern)) {
		printf("ERROR! Pattern must only contain 0s and 1s.");
		return -1;
	}

	for (i = 0; i < PATTERN_SIZE; i++) {
		for (j = 0; j < PATTERN_SIZE; j++)
			grid[i+4][j+4] = pattern[i][j];
	}

	for (i = 0; i < 100; i++) {
		printf("\n\nStep %d:\n", i+1);
		display_grid(grid);
		generate_next_step(grid);
	}
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
			if (0 <= k && k < SIZE && 0 <= l && l < SIZE) {
				if (k == i && l == j)
					continue;
				if (grid[k][l])
					alive += 1;
			}
		}
	}

	return alive;
}

int input_pattern(int pattern[PATTERN_SIZE][PATTERN_SIZE])
{
	char c;
	int i, j, c_num;

	for (i = 0; i < PATTERN_SIZE; i++) {
		for (j = 0; j < PATTERN_SIZE; j++) {
			c = getchar();
			pattern[i][j] = (int) (c - '0');
		}
		skipgarb();
	}

	return TRUE;
}

void skipgarb()
{
	while (getchar() != '\n') {
		;
	}
}