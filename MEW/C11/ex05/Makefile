# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 14:00:19 by chly-huc          #+#    #+#              #
#    Updated: 2019/11/14 14:25:14 by chly-huc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 		do_op.c do_op2.c do_op3.c
HEADERS =	includes
NAME = 		./do-op
CC = 		gcc
CFLAGS =	-Wall -Wextra -Werror
OBJS = 		${SRCS:.c=.o}

.c.o:
			${CC} ${CFLAGS} -I${HEADERS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY: clean fclean re  all