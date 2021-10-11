NAME = so_long

SRC  =	so_long.c utils1.c utils2.c utils3.c utils4.c utils5.c parsing.c draw.c control.c

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

.PHONY:		all clean fclean re