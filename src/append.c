/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:39:33 by mrassokh          #+#    #+#             */
/*   Updated: 2016/12/18 14:31:07 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_append(t_result *res, t_list *cursor, size_t i, size_t j)
{
	t_tetrimino		*t;

	t = cursor->content;
	t->shift_x = t->acc_x;
	while (t->shift_x)
	{
		if (check_shift(t, res, i, j))
			return (1);
		(t->shift_x)--;
	}
	return (check_shift(t, res, i, j));
}

int		check_shift(t_tetrimino *t, t_result *res, size_t i, size_t j)
{
	size_t		row;
	size_t		col;
	size_t		x;
	size_t		y;

	row = i;
	x = 0;
	if (j + t->width_cut - t->shift_x > res->side)
		return (0);
	if (j < t->shift_x)
		return (0);
	if (i + t->height_cut > res->side)
		return (0);
	while (row < i + t->height_cut)
	{
		col = j - t->shift_x;
		y = 0;
		while (col < j + t->width_cut)
			if (!compatible_check(res->square[row][col++], t->tetrada[x][y++]))
				return (0);
		row++;
		x++;
	}
	return (1);
}

int		compatible_check(char fig, char tetr)
{
	if (ft_isalpha(fig) && ft_isalpha(tetr))
		return (0);
	return (1);
}
