/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:38:54 by mrassokh          #+#    #+#             */
/*   Updated: 2016/12/28 13:23:44 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill(char *c, char buf, int num)
{
	if (buf == '#')
		*c = 'A' + num;
	else
		*c = buf;
}

void	processing(size_t *i, t_tetrimino **c, size_t *f, t_list **l)
{
	*f = 0;
	(*i)++;
	near_check(c);
	if (!((*l) = ft_lstnew((t_tetrimino *)(*c), sizeof(t_tetrimino))))
		exit(1);
}

int		check_n(int fd, char *buffer, size_t *flag_n)
{
	if (read(fd, buffer, B_SIZE) > 0)
	{
		if (buffer[0] == '\n')
		{
			*flag_n = 1;
			return (1);
		}
		else
			error(2);
	}
	return (0);
}
