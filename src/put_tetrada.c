/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetrada.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:04:56 by mrassokh          #+#    #+#             */
/*   Updated: 2016/12/18 14:37:10 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_put(char fig, char tetr)
{
	if (!ft_isalpha(fig) && ft_isalpha(tetr))
		return (1);
	return (0);
}

void			put_tetrada(t_result **res, t_list *cursor, size_t i, size_t j)
{
	size_t		row;
	size_t		col;
	size_t		x;
	size_t		y;

	row = i;
	x = 0;
	while (row < i + ((t_tetrimino *)cursor->content)->height_cut)
	{
		col = j - ((t_tetrimino *)cursor->content)->shift_x;
		y = 0;
		while (col < j + ((t_tetrimino *)cursor->content)->width_cut)
		{
			if (check_put((*res)->square[row][col],
					((t_tetrimino *)cursor->content)->tetrada[x][y]))
				(*res)->square[row][col] = ((t_tetrimino *)cursor->content)
											->tetrada[x][y];
			col++;
			y++;
		}
		row++;
		x++;
	}
}

void			delete_tetrada(t_result **res, t_list *precursor)
{
	char	**square;
	size_t	i;
	size_t	j;

	square = (*res)->square;
	i = 0;
	while (square[i])
	{
		j = 0;
		while (square[i][j])
		{
			if (square[i][j] == ((t_tetrimino *)precursor->content)->al)
				square[i][j] = '.';
			j++;
		}
		i++;
	}
}
