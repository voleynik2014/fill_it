#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 08:21:33 by mrassokh          #+#    #+#              #
#    Updated: 2017/01/03 10:28:37 by mrassokh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

C = gcc
FLAGS = -Wall -Wextra -Werror
SRC = fillit.c print_square.c read_input.c error.c near_check.c fill.c\
		prepare_list.c define_tetrada.c recurse_connection.c\
		append.c put_tetrada.c ft_putendl.c ft_memalloc.c ft_strnew.c\
		ft_lstnew.c ft_bzero.c ft_isalpha.c ft_lstiter.c \
		ft_memcpy.c ft_memdel.c ft_memset.c ft_putendl_fd.c ft_putstr.c\
		ft_putchar.c ft_putstr_fd.c ft_putchar_fd.c ft_listpushback.c
NAME = fillit
OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

SRCDIR  = ./src/
INCDIR  = ./includes/
OBJDIR  = ./obj/

all: obj $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(C) $(FLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
		$(C) -o $(NAME) $(OBJ)
clean:
		rm -rf $(OBJDIR) *~

fclean: clean
		rm -rf $(NAME)

re:	fclean all
