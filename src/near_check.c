/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   near_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 09:54:53 by mrassokh          #+#    #+#             */
/*   Updated: 2016/12/04 15:06:00 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	isnear(char **check, int i, int j)
{
	int		connect;

	connect = 0;
	if (i < 3 && ft_isalpha(check[i + 1][j]))
		connect++;
	if (j < 3 && ft_isalpha(check[i][j + 1]))
		connect++;
	if (i > 0 && ft_isalpha(check[i - 1][j]))
		connect++;
	if (j > 0 && ft_isalpha(check[i][j - 1]))
		connect++;
	return (connect);
}

static int	connection_check(int *number, char **check, int i, int j)
{
	int		near;

	near = 0;
	(*number)++;
	near = isnear(check, i, j);
	if (!near)
		error(3);
	return (near);
}

int			near_check(t_tetrimino **content)
{
	int		i;
	int		j;
	int		number;
	int		near;

	i = 0;
	number = 0;
	near = 0;
	while (i++ < 4)
	{
		j = 0;
		while (j++ < 4)
			if (ft_isalpha((*content)->in_tetr[i - 1][j - 1]))
				near = near + connection_check(&number,
						(*content)->in_tetr, i - 1, j - 1);
	}
	if (number == 4 && near > 5)
		return (1);
	else if (near <= 5)
		error(3);
	else
		error(4);
	return (0);
}
