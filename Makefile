CC = cc 
CFLAGS =  -Wall -Wextra -Werror -g


HELPERS_SRC = src/helpers/ft_strchr.c src/helpers/error_handler.c \
			src/helpers/map_parsser.c src/helpers/render.c \
			src/helpers/ft_itoa.c src/helpers/player_moves.c
GET_NEXT_LINE_SRC = src/get_next_line/get_next_line_utils.c \
					src/get_next_line/get_next_line.c 

SO_LONG_SRC = src/so_long.c ${GET_NEXT_LINE_SRC} ${HELPERS_SRC}
SO_LONG_OBJ = ${SO_LONG_SRC:.c=.o}

NAME = so_long

.c.o: 
	${CC} ${CFLAGS} -c $< -o $@

all:  ${NAME}

${NAME}: ${SO_LONG_OBJ}
	${CC} ${CFLAGS}  -Lmlx -lmlx -framework OpenGL -framework AppKit ${SO_LONG_OBJ} -o ${NAME}

${SO_LONG_OBJ}: ${PUSH_SWAP_SRC}

clean:
	rm -rf ${SO_LONG_OBJ}
fclean: clean
	rm -rf  ${NAME}
re: fclean all

.PHONY: clean fclean re


