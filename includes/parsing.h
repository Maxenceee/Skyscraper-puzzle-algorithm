/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:51:11 by mgama             #+#    #+#             */
/*   Updated: 2022/11/08 13:51:12 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARSING_H__
#define __PARSING_H__

int check_arguments(int argc, char *argv[]);
/* check if arguments given to the main function are as expected */

int *convert_pattern(char *str);
/* takes a string representing each points of view of the puzzle and convert it in an array of `int` */

void print_puzzle_grid(int grid[4][4]);
/* display a 4X4 grid given */

#endif