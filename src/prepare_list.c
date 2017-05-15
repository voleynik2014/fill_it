/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:58:47 by mrassokh          #+#    #+#             */
/*   Updated: 2016/12/28 14:18:23 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		create_tetrada(t_tetrimino *content, size_t height, size_t width)
{
	size_t		i;

	i = 0;
	content->tetrada = (char**)malloc(sizeof(char *) * (height + 1));
	while (i < height)
		(content->tetrada)[i++] = ft_strnew(width + 1);
	content->tetrada[height] = NULL;
	content->valent = 0;
	content->acc_x = 0;
}

void		fill_tetrada(t_tetrimino *content, size_t w_0, size_t h_0)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < content->height_cut)
	{
		j = 0;
		while (j < content->width_cut)
		{
			(content->tetrada)[i][j] = (content->in_tetr)[h_0 + i][w_0 + j];
			if (ft_isalpha((content->tetrada)[i][j]) & (i == 0 || j == 0))
				(content->valent)++;
			else
			{
				if (i == 0 && content->valent == 0)
					(content->acc_x)++;
			}
			j++;
		}
		i++;
	}
}

void		cut(t_list *elem)
{
	int		w_0;
	int		h_0;
	int		i;
	int		j;

	w_0 = -1;
	h_0 = -1;
	i = 0;
	while (i < (int)((t_tetrimino *)(elem->content))->height)
	{
		j = 0;
		while (j < (int)((t_tetrimino*)elem->content)->width + 1)
		{
			if (ft_isalpha(((t_tetrimino *)elem->content)->in_tetr[i][j]))
			{
				define_tetrada_width(&w_0, j, elem);
				define_tetrada_height(&h_0, i, elem);
			}
			j++;
		}
		i++;
	}
	create_tetrada(elem->content, ((t_tetrimino*)elem->content)->height_cut,
						((t_tetrimino *)elem->content)->width_cut);
	fill_tetrada(elem->content, w_0, h_0);
}

void		prepare_list(t_list **tetr)
{
	ft_lstiter(*tetr, &cut);
}
