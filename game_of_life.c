#include <stdio.h>

#define HSIZE 100
#define VSIZE 100

int main()
{
	int i, j;
	int grid[HSIZE][VSIZE];

	for (i = 0; i < HSIZE; i++)
		for (j = 0; j < VSIZE; j++)
			grid[i][j] = 0;
}
