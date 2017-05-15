/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:29:18 by mrassokh          #+#    #+#             */
/*   Updated: 2016/12/18 14:12:38 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_square(char **square)
{
	int		i;

	if (!square)
		return ;
	i = 0;
	while (square[i++])
		ft_putendl(square[i - 1]);
}
