# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/24 01:22:24 by zcarde            #+#    #+#              #
#    Updated: 2015/02/19 01:11:30 by zcarde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c ft_atoi.c ft_putnbr.c options.c ft_putstr_fd.c \
ft_putchar_fd.c ft_strlen.c ft_strncmp.c ft_putstr.c ft_putchar.c algos.c \
errors.c fonctions_pile.c gestion_piles.c higher_lower.c print_piles.c

OBJ=$(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -ggdb3

INCLUDE = push_swap.h


all : $(NAME)

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ)

%.o: %.c
	gcc -c $(FLAGS) $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
