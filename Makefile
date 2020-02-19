SRCS_PATH = ./srcs/

SRCS = parsing_data.c parsing_texture.c start.c errorexit.c main.c parsing_map.c

UTILS_PATH = ./srcs/utils/

UTILS = get_next_line.c get_next_line_utils.c ft_strnstr.c ft_split.c ft_lstadd_back.c ft_lstclear.c \
ft_lstdelone.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_putstr_fd.c ft_strnstr.c ft_atoipositif.c

OBJS = ${addprefix ${SRCS_PATH}, ${SRCS:.c=.o}}

OBJS_UTILS = ${addprefix ${UTILS_PATH}, ${UTILS:.c=.o}}

CFLAGS = -Wall -Wextra -Werror

CC = gcc

NAME = Cub3D

$(NAME): ${OBJS} ${OBJS_UTILS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_UTILS}

all: ${NAME}

clean:
	rm -rf ${OBJS} ${OBJS_UTILS}

fclean: clean
	rm -rf ${NAME}

re:	fclean all