/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:51:13 by mgama             #+#    #+#             */
/*   Updated: 2022/11/12 17:10:45 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SOLVING_H__
#define __SOLVING_H__

int check_cell(int grid[4][4], int gap, int pattern[16]);
/* check if proposed number should be in the current cell */

int check_col_up(int grid[4][4], int gap, int pattern[16]);
/* check if proposed number fulfills the conditions from top */

int check_row_right(int grid[4][4], int gap, int patern[16]);
/* check if proposed number fulfills the conditions from right side */

int check_col_down(int grid[4][4], int gap, int pattern[16]);
/* check if proposed number fulfills the conditions from bottom */

int check_row_left(int grid[4][4], int gap, int pattern[16]);
/* check if proposed number fulfills the conditions from left side */

#endif