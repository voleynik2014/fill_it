/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_tetrada.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:50:14 by mrassokh          #+#    #+#             */
/*   Updated: 2016/12/06 13:51:47 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	define_tetrada_width(int *w_0, int j, t_list *elem)
{
	size_t	*width_cut;

	width_cut = &((t_tetrimino *)elem->content)->width_cut;
	if (*w_0 < 0)
	{
		*w_0 = j;
		(*width_cut)++;
	}
	else
	{
		if (j + 1 > *w_0 + (int)(*width_cut))
			(*width_cut)++;
		else if (j < *w_0)
		{
			*width_cut = *width_cut + *w_0 - j;
			*w_0 = j;
		}
	}
}

void	define_tetrada_height(int *h_0, int i, t_list *elem)
{
	size_t	*height_cut;

	height_cut = &((t_tetrimino *)elem->content)->height_cut;
	if (*h_0 < 0)
	{
		*h_0 = i;
		(*height_cut)++;
	}
	else if ((int)(*h_0 + *height_cut) < i + 1)
		(*height_cut)++;
}
