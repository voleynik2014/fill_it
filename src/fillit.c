/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 08:31:21 by mrassokh          #+#    #+#             */
/*   Updated: 2016/12/28 14:16:23 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list	*tetr;
	char	**square;
	int		num;

	tetr = NULL;
	num = 0;
	if (argc != 2)
	{
		ft_putendl_fd("Usage: fillit list_of_tetriminos", 1);
		return (1);
	}
	tetr = read_input(argv[1], &num);
	prepare_list(&tetr);
	square = recurse_connection(tetr, num - 1);
	print_square(square);
	return (0);
}
