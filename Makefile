SRCS_PATH = /srcs/

SRCS = parsing.c

UTLS_PATH = /srcs/utils/

UTILS = get_next_line.c get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

OBJS_UTILS = ${UTILS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = gcc

NAME = Cub3D

$(NAME): ${OBJS}

all: ${NAME}

clean:
	rm -rf ${OBJS} ${OBJS_UTILS}

fclean: clean
	rm -rf ${NAME}

re:	fclean all