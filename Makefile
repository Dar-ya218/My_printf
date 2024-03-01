# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 15:31:01 by dabochko          #+#    #+#              #
#    Updated: 2024/03/01 13:46:05 by dabochko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putchar.c ft_putnbr.c\
	ft_putstr.c ft_putunbr.c ft_putnbr.c ft_puthex.c ft_putptr.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:%.c Makefile ft_printf.h
	gcc $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
