NAME = so_long

SRC  =	src/so_long.c src/utils1.c src/utils2.c src/utils3.c src/utils4.c src/utils5.c src/parsing.c src/draw.c src/control.c

MLX  = -L./minilibX/ ./minilibX/libmlx.a -lm -lmlx -lX11 -lXext -lbsd

OBJ  = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	@rm -rf so_long
	@gcc -o $(NAME) $(OBJ) $(MLX) -Wall -Wextra -Werror -fsanitize=address

all : $(NAME)

clean :
	${RM} ${OBJ}

fclean:		clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re