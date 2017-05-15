/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_connection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 10:39:51 by mrassokh          #+#    #+#             */
/*   Updated: 2016/12/28 14:49:41 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		find_min_side(int num)
{
	size_t	i;

	i = 0;
	while ((i * i) < (size_t)(4 * num))
		i++;
	return (i);
}

t_result	*create_result(size_t side)
{
	t_result	*cont;
	size_t		i;

	cont = (t_result *)malloc(sizeof(t_result));
	if (!cont)
		exit(0);
	cont->side = side;
	i = 0;
	cont->square = (char**)malloc(sizeof(char *) * (side + 1));
	if (!cont->square)
		exit(0);
	while (i < side)
	{
		cont->square[i] = ft_strnew(side + 1);
		ft_memset((char*)cont->square[i], '.', side);
		ft_memset((char*)(cont->square[i++] + side + 1), '\n', 1);
	}
	cont->square[side] = NULL;
	return (cont);
}

void		clear_result(t_result **res)
{
	int		i;

	i = 0;
	while ((*res)->square[i++])
		free((*res)->square[i - 1]);
	free(*res);
	(*res) = NULL;
}

int			append(t_result **res, t_list *cursor, t_list *precursor)
{
	size_t		i;
	size_t		j;

	if (!cursor)
		return (1);
	i = 0;
	while ((*res)->square[i])
	{
		j = 0;
		while ((*res)->square[i][j])
		{
			if (check_append((*res), cursor, i, j))
			{
				put_tetrada(res, cursor, i, j);
				if (append(res, cursor->next, cursor))
					return (1);
			}
			j++;
		}
		i++;
	}
	if (precursor)
		delete_tetrada(res, precursor);
	return (0);
}

char		**recurse_connection(t_list *tetr, int num)
{
	size_t		min_side;
	t_result	*res;
	t_list		*cursor;
	char		**ret;

	min_side = find_min_side(num);
	res = create_result(min_side);
	cursor = tetr;
	while (!(append(&res, cursor, NULL)))
	{
		min_side++;
		clear_result(&res);
		res = create_result(min_side);
	}
	ret = res->square;
	return (ret);
}
