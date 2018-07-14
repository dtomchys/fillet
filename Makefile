#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 16:37:00 by dtomchys          #+#    #+#              #
#    Updated: 2017/11/22 12:33:31 by dtomchys         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
NAME = fillit
CFLAGS = -Wall -Wextra -Werror 
SRC = main.c ft_fillit_reader.c ft_create_tet.c ft_up_left.c\
	ft_create_final_field.c ft_put_field.c ft_make_list.c ft_print_field.c\
	ft_bzero.c ft_memdel.c ft_memset.c ft_putstr.c ft_strnew.c ft_strsplit.c\
	ft_strlen.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) $(SRC) -c

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
