NAME = fractol
SRCS = srcs/main.c \
	   srcs/color.c \
	   srcs/fractal.c \
	   srcs/init_fractal.c \
	   srcs/draw.c \
	   srcs/hook.c

OBJS = $(SRCS:srcs/%.c=%.o)
LIB = -L./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit -L./libft/ -lft
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f
I = -I./includes \
	-I./libft \

$(NAME):
	make -C libft/
	make -C minilibx_macos/
	$(CC) $(CFLAGS) $(I) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
