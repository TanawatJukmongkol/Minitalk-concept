# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 06:32:57 by tjukmong          #+#    #+#              #
#    Updated: 2023/02/25 21:46:31 by tjukmong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= server
SRCS1		= server.c server_util.c

NAME2		= client
SRCS2		= client.c server_util.c

SRC_DIR		= ./src/
LIB_DIR		= ./lib/
BUILD_DIR	= ./build/

SRC1			= ${addprefix ${BUILD_DIR},${SRCS1}}
OBJ1			= ${SRC1:.c=.o}

SRC2			= ${addprefix ${BUILD_DIR},${SRCS2}}
OBJ2			= ${SRC1:.c=.o}

CC			= gcc
CFLAG		= -g -Wall -Werror -Wextra -O3



all: library ${BUILD_DIR} ${NAME1} ${NAME2}

library:
	find ${LIB_DIR} -mindepth 1 -maxdepth 1 -exec make -C {} \;

clean:
	rm -f $(OBJ1) $(OBJ2)

fclean: clean
	rm -f ${NAME1} ${NAME2}

re: fclean all

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

${BUILD_DIR}%.o:${SRC_DIR}%.c
	$(CC) -c -o $@ $^

${NAME1}: ${OBJ1}
	$(CC) ${OBJ1} ${wildcard ${LIB_DIR}/*/*.a} -o ${NAME1} $(CFLAG)

${NAME2}: ${OBJ2}
	$(CC) ${OBJ2} ${wildcard ${LIB_DIR}/*/*.a} -o ${NAME2} $(CFLAG)

.PHONY:	all library clean fclean re
