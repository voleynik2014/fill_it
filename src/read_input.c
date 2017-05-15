/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:58:55 by mrassokh          #+#    #+#             */
/*   Updated: 2017/01/03 10:26:14 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		create_elem(t_tetrimino *content, int width, int height, int n)
{
	int		i;

	i = 0;
	content->in_tetr = (char**)malloc(sizeof(char *) * (height + 1));
	while (i < height)
		content->in_tetr[i++] = ft_strnew(width + 1);
	content->in_tetr[height] = NULL;
	content->height = height;
	content->width = width;
	content->height_cut = 0;
	content->width_cut = 0;
	content->shift_x = 0;
	content->al = 'A' + n;
}

static int		check(char buffer, int j)
{
	if (j < 4)
		if (buffer != '#' && buffer != '.')
			error(1);
	if (j == 4)
		if (buffer != '\n')
			error(1);
	return (1);
}

static int		fill_elem(t_tetrimino **content, int fd, int num, char *buffer)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	while (i < 4 && ret != -10)
	{
		j = 0;
		while (j++ < 5)
		{
			if ((ret = read(fd, buffer, B_SIZE)) > 0 && check(buffer[0], j - 1))
				fill(&((*content)->in_tetr[i][j - 1]), buffer[0], num);
			else
			{
				ret = -10;
				break ;
			}
		}
		i++;
	}
	if (i == 1 && j == 1)
		return (0);
	if (i != 4 || j != 6)
		error(2);
	return (ret);
}

static int		load(t_list **begin, int fd, int *num, t_tetrimino **c)
{
	char		buffer[B_SIZE];
	t_list		*lst_new;
	int			ret;
	size_t		i;
	size_t		flag_n;

	i = 0;
	ret = 1;
	while (ret)
	{
		*c = (t_tetrimino *)malloc(sizeof(t_tetrimino));
		create_elem(*c, 4, 4, *num);
		if (!(ret = fill_elem(c, fd, (*num)++, buffer)))
		{
			if (flag_n == 1)
				error(3);
			else
				break ;
		}
		processing(&i, c, &flag_n, &lst_new);
		ft_lstpushback(begin, lst_new);
		if ((ret = check_n(fd, buffer, &flag_n)))
			continue;
	}
	return (i);
}

t_list			*read_input(const char *input, int *num)
{
	t_list		*tetr;
	int			fd;
	t_tetrimino *content;

	tetr = NULL;
	fd = open(input, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("error", 1);
		exit(1);
	}
	if (!load(&tetr, fd, num, &content))
		error(1);
	close(fd);
	return (tetr);
}
