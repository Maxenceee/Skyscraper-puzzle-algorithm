/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:51:08 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 13:51:09 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAIN_H__
#define __MAIN_H__

int check_adjacent_cell(int grid[4][4], int gap, int num);
/* return if the number given already exist in the row and column where it is */

int puzzle_solver(int grid[4][4], int pattern[16], int gap);
/* solver function, takes a matrix of `int` and an array of all entries as arguments, return 1 if solution exist and 0 if not */

#endif