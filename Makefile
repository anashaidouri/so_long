# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 23:41:00 by ahaidour          #+#    #+#              #
#    Updated: 2023/02/04 10:08:53 by ahaidour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = so_long.c libft/ft_strlenlib.c libft/ft_strjoin.c libft/ft_substr.c libft/ft_split.c libft/ft_calloc.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/ft_bzero.c \
	libft/ft_strchr.c ft_printf/handle_conversion.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putnbr_hex.c\
	ft_printf/ft_putnbr_unsigned.c ft_printf/ft_putstr.c ft_printf/ft_printf.c \
	check.c check2.c dimensions.c path_check.c display.c moves.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o so_long

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
