SRCS = main.c read_map.c draw.c utils.c

FLAGS = -Lmlx -lmlx -Ofast -framework OpenGL -g -framework AppKit

LIBS = ./libft/libft.a

NAME = fdf

all:
	gcc $(SRCS) $(LIBS) $(FLAGS) -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all

# //-fsanitize=address
# -lXext -LXext -lx11 -LX11