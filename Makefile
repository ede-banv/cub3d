# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 20:55:42 by ede-banv          #+#    #+#              #
#    Updated: 2020/03/08 01:23:13 by ede-banv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror
DEBUG = -g3 -fsanitize=address


MLX_PATH = ./minilibx_opengl_20191021/
MLX_NAME = libmlx.a

PARSING_PATH = parsing/
PARSING = parsing_data.c parsing_texture.c parsing_map.c parsing_check.c \
parsing_end.c
SRCS_PARSING = ${addprefix ${PARSING_PATH}, ${PARSING}}

UTILS_PATH = utils/
UTILS = get_next_line.c get_next_line_utils.c ft_atoipositif.c
SRCS_UTILS = ${addprefix ${UTILS_PATH}, ${UTILS}}

TRACING_PATH = tracing/
TRACING = tracing.c
SRCS_TRC = ${addprefix ${TRACING_PATH}, ${TRACING}}

SRCS_PATH = ./srcs/
SRCS = start.c errorexit.c main.c ${SRCS_PARSING} ${SRCS_UTILS} ${SRCS_TRC}

LIBFT_PATH = ./libft/
LIBFT = libft.a

OBJS = ${addprefix ${SRCS_PATH}, ${SRCS:.c=.o}}

$(NAME): ${OBJS} ${OBJS_UTILS} ${OBJS_PARSING} ${MLX_PATH}${MLX_NAME} ${LIBFT_PATH}${LIBFT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L ${MLX_PATH} -L ${LIBFT_PATH} -lft -lmlx -framework OpenGL -framework AppKit

all: ${NAME}

debug: all
	${CC} ${CFLAGS} $(DEBUG) -o ${NAME} ${OBJS} -L ${MLX_PATH} -L ${LIBFT_PATH} -lft -lmlx -framework OpenGL -framework AppKit

$(LIBFT_PATH)$(LIBFT): ${LIBFT_PATH}libft.h
	make -C ${LIBFT_PATH}

$(MLX_PATH)$(MLX_NAME):
	make -C ${MLX_PATH}

clean:
	rm -rf ${OBJS} ${OBJS_UTILS} ${OBJS_PARSING}
	make clean -C ${LIBFT_PATH}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${LIBFT_PATH}${LIBFT}

re:	fclean all
