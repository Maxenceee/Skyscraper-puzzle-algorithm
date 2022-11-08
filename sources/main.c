/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:51:34 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 14:14:09 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "solving.h"
#include "parsing.h"
#include "generic.h"
#include <stdlib.h>

int check_adjacent_cell(int grid[4][4], int gap, int num)
{
	int i;

	i = 0;
	/* for each columns of the grid */
	while (i < gap / 4)
	{
		/* test if the value of `num` is present */
		if (grid[i][gap % 4] == num)
			return (1);
		i++;
	}
	i = 0;
	/* for each rows of the grid */
	while (i < gap % 4)
	{
		/* test if the value of `num` is present */
		if (grid[gap / 4][i] == num)
			return (1);
		i++;
	}
	return (0);
}

int puzzle_solver(int grid[4][4], int pattern[16], int gap)
{
	int num;

	/* if solver reaches end, it returns that the grid is solved */
	if (gap == 16)
		return (1);
	num = 0;
	while (++num <= 4)
	{
		/* check if the new supposed nul is already in */
		if (check_adjacent_cell(grid, gap, num) == 0)
		{
			/* put new supposed value in the grid */
			grid[gap / 4][gap % 4] = num;
			/* check if new number is correct */
			if (check_cell(grid, gap, pattern) == 0)
			{
				/* go to next cell */
				if (puzzle_solver(grid, pattern, gap + 1) == 1)
					return (1);
			}
			/* if not remove it */
			else
			{
				grid[gap / 4][gap % 4] = 0;
			}
		}
	}
	/* if any solution can be find return that the grid cannot be solved */
	return (0);
}

int main(int argc, char *argv[])
{
	int grid[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	};
	int *pattern;

	/* if incorrect arguments in the user entries end the program */
	if (check_arguments(argc, argv) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	/* convert the string pattern as an array of `int` */
	pattern = convert_pattern(argv[1]);
	if (!pattern)
		return (1);
	/* call main program function */
	if (puzzle_solver(grid, pattern, 0) == 1)
	{
		/* if a solution is found display it */
		print_puzzle_grid(grid);
	}
	/* otherwise display error */
	else
	{
		ft_putstr("Error\n");
	}
	return (0);
}
