CC = cc 
CFLAGS =  -Wall -Wextra -Werror -g
# FLAGS FOR MLX LIBRARIES
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

# HELPERS SRC
HELPERS_SRC = src/helpers/ft_putstr.c src/helpers/ft_strlen.c \
			src/helpers/ft_strdup.c src/helpers/ft_strjoin.c \
			src/helpers/ft_substr.c src/helpers/ft_strchr.c \
			src/helpers/ft_last_char.c src/helpers/is_only_char.c \
			src/helpers/trim_new_line.c src/helpers/ft_itoa.c

# UTILITIES SRC
UTILITIES_SRC = src/utilities/error_handler/throw_error.c \
				src/utilities/map_parser/map_parser.c \
				src/utilities/map_parser/check_extension.c \
				src/utilities/get_next_line/get_next_line.c \
				src/utilities/map_parser/count_lines.c \
				src/utilities/map_parser/fill_map.c \
				src/utilities/map_parser/map_chr.c \
				src/utilities/game_controller/load_assets.c \
				src/utilities/game_controller/init_game.c \
				src/utilities/game_controller/player_moves.c \
				src/utilities/game_controller/render.c

# ALL SRCS
SO_LONG_SRC = src/so_long.c ${HELPERS_SRC} ${UTILITIES_SRC}

# ALL OBJS
SO_LONG_OBJ = ${SO_LONG_SRC:.c=.o}

# NAME OF THE PROGRAMME
NAME = so_long

.c.o: 
	${CC} ${CFLAGS} -c $< -o $@

all:  ${NAME}

${NAME}: ${SO_LONG_OBJ}
	${CC} ${CFLAGS} ${MLX_FLAGS} ${SO_LONG_OBJ}  -o ${NAME}

${SO_LONG_OBJ}: ${PUSH_SWAP_SRC}

clean:
	rm -rf ${SO_LONG_OBJ}
fclean: clean
	rm -rf  ${NAME}
re: fclean all

.PHONY: clean fclean re