/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 08:32:40 by mrassokh          #+#    #+#             */
/*   Updated: 2017/01/05 16:25:33 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define B_SIZE 1

typedef struct		s_tetrimino
{
	char			**in_tetr;
	char			**tetrada;
	char			al;
	size_t			height;
	size_t			height_cut;
	size_t			width;
	size_t			width_cut;
	size_t			valent;
	size_t			acc_x;
	size_t			shift_x;
}					t_tetrimino;

typedef struct		s_result
{
	char			**square;
	size_t			side;
	char			al;
}					t_result;

t_list				*read_input(const char *input, int *num);
void				print_square(char **square);
void				error(int err_ind);
int					near_check(t_tetrimino **content);
void				fill(char *c, char buf, int num);
void				processing(size_t *i,
								t_tetrimino **c, size_t *f, t_list **l);
int					check_n(int fd, char *buffer, size_t *flag_n);
void				prepare_list(t_list **tetr);
void				define_tetrada_height(int *h_0, int i, t_list *elem);
void				define_tetrada_width(int *w_0, int j, t_list *elem);
char				**recurse_connection(t_list *tetr, int num);
t_result			*create_result(size_t side);
void				fill_result(t_list *result, t_list *tetr, t_list *hedgehog);
int					append(t_result **res, t_list *cursor, t_list *precursor);
void				put_tetrada(t_result **res, t_list *cursor, size_t i,
								size_t j);
void				delete_tetrada(t_result **res, t_list *precursor);
int					check_append(t_result *res, t_list *cursor, size_t i,
								size_t j);
int					check_shift(t_tetrimino *t, t_result *res, size_t i,
								size_t j);
int					compatible_check(char fig, char tetr);
void				ft_lstpushback(t_list **alst, t_list *new);
#endif
