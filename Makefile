# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/27 12:57:59 by rpinoit           #+#    #+#              #
#    Updated: 2018/03/23 13:01:35 by rpinoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = srcs/main.c \
	   srcs/color.c \
	   srcs/fractal.c \
	   srcs/init_fractal.c \
	   srcs/draw.c \
	   srcs/hook.c \
	   srcs/action.c

OBJS = $(SRCS:srcs/%.c=%.o)
LIB = -L./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit -L./libft/ -lft
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f
I = -I./includes \
	-I./libft

$(NAME):
	make -C libft/
	make -C minilibx_macos/
	$(CC) $(CFLAGS) $(I) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
