#include "main.h"
#include "solving.h"
#include "parsing.h"
#include "generic.h"
#include <stdlib.h>

int check_adjacent_cell(int grid[4][4], int gap, int num)
{
	int i;

	i = 0;
	/* for each columns */
	while (i < gap / 4)
	{
		/* test if num is present */
		if (grid[i][gap % 4] == num)
			return (1);
		i++;
	}
	i = 0;
	/* for each rows */
	while (i < gap % 4)
	{
		/* test if num is present */
		if (grid[gap / 4][i] == num)
			return (1);
		i++;
	}
	return (0);
}

int puzzle_solver(int grid[4][4], int patern[16], int gap)
{
	int size;

	/* if solver reaches end return that the grid is resolved */
	if (gap == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		if (check_adjacent_cell(grid, gap, size) == 0)
		{
			/* put new number in the grid */
			grid[gap / 4][gap % 4] = size;
			/* check if new number is correct */
			if (check_cell(grid, gap, patern) == 0)
			{
				/* go to next solve */
				if (puzzle_solver(grid, patern, gap + 1) == 1)
					return (1);
			}
			/* if not remove it */
			else
			{
				grid[gap / 4][gap % 4] = 0;
			}
		}
	}
	/* if any solution can be find return 0 */
	return (0);
}

int main(int argc, char *argv[])
{
	/* define grid */
	int grid[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	};
	int *patern;

	/* if incorrect arguments end the program */
	if (check_arguments(argc, argv) == 1)
	{
		return (0);
	}
	/* convert the string patern as an array of `int` */
	patern = convert_patern(argv[1]);
	/* call main program function, if a solution is found display it */
	if (puzzle_solver(grid, patern, 0) == 1)
	{
		print_puzzle_grid(grid);
	}
	/* otherwise display error */
	else
	{
		ft_putstr("Error\n");
	}
	return (0);
}
