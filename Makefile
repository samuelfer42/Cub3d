NAME	= Cub3D

SRCS=	src/main.c					\
		src/mlx_funcs.c				\
		src/structs_funcs.c			\
		src/raycast.c				\
		src/print.c					\
		src/parsing_funcs.c			\
		src/parsing_map.c			\
		src/parsing_main.c			\
		src/get_next_line.c			\
		src/get_next_line_utils.c	\
		src/move.c					\
		src/debug.c					\
		src/dda.c					\
		src/textures.c				\
		src/map_allocation.c		\
		src/save.c					\
		src/parsing_funcs2.c		\

CFLAGS	= -Wall -Wextra -Werror
OBJS	= ${SRCS:.c=.o}

all:		${NAME}


$(NAME):	${OBJS}
		gcc ${OBJS} -I mlx libmlx.dylib -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c
		gcc -Wall -Wextra -Werror -Imlx -Iinc -Ilibft -c $< -o $@

clean:	
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

.PHONY:		clean fclean
