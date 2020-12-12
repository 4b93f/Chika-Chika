# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/11 16:28:13 by chly-huc          #+#    #+#              #
#    Updated: 2020/12/12 17:16:06 by chly-huc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS   = ft_strcmp.s
HEADERS =	libasm.h
NAME = 		libasm.a
OBJS = 		${SRCS:.s=.o}
CC = cc -c


.s.o:
		@nasm -fmacho64 ${SRCS}

${NAME}: 	${OBJS}
			@ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:	
			@rm -f ${OBJS} ${OBJ}

fclean:		clean
			@rm -f ${NAME} ${OBJ}

clarify:	clean

re:			fclean all

.PHONY : fclean all re clean