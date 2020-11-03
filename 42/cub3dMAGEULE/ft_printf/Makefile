# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 23:53:03 by chly-huc          #+#    #+#              #
#    Updated: 2020/11/03 16:31:17 by chly-huc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS   = 	convert_base.c \
			convert_base2.c \
			ft_adress.c \
			ft_character.c \
			ft_find_specifier.c \
			ft_hexa_caps.c \
			ft_hexa.c \
			ft_integer.c \
			ft_percentage.c \
			ft_printf.c \
			ft_search_params.c \
			ft_string.c \
			ft_unsigned_int.c \
			ft_utils.c \
			ft_utils2.c \
			ft_utils3.c \
			../libft/ft_atoi.c \
			../libft/ft_bzero.c \
			../libft/ft_calloc.c \
			../libft/ft_isalnum.c \
			../libft/ft_isalpha.c \
			../libft/ft_isascii.c \
			../libft/ft_isdigit.c \
			../libft/ft_isprint.c \
			../libft/ft_memccpy.c \
			../libft/ft_memchr.c \
			../libft/ft_memcmp.c \
			../libft/ft_memcpy.c \
			../libft/ft_memmove.c \
			../libft/ft_memset.c \
			../libft/ft_strchr.c \
			../libft/ft_strdup.c \
			../libft/ft_strlcat.c \
			../libft/ft_strlcpy.c \
			../libft/ft_strlen.c \
			../libft/ft_strncmp.c \
			../libft/ft_strnstr.c \
			../libft/ft_strrchr.c \
			../libft/ft_tolower.c \
			../libft/ft_toupper.c \
			../libft/ft_substr.c \
			../libft/ft_strjoin.c \
			../libft/ft_strtrim.c \
			../libft/ft_split.c \
			../libft/ft_itoa.c \
			../libft/ft_strmapi.c \
			../libft/ft_putchar_fd.c \
			../libft/ft_putstr_fd.c \
			../libft/ft_putendl_fd.c \
			../libft/ft_putnbr_fd.c \


HEADERS =	ft_printf.h
NAME = 		libftprintf.a
CC = 		gcc
CFLAGS =	-Wall -Wextra -Werror
OBJS = 		${SRCS:.c=.o}

.c.o:
			@${CC} ${CFLAGS} -I ${HEADERS} -c $^ -o ${<:.c=.o}

${NAME}: 	${OBJS}
			@ar rc ${NAME} ${OBJS}

all:		${NAME}

bonus:		${OBJ}
			@ar rc ${NAME} ${OBJ} 	
clean:	
			@rm -f ${OBJS} ${OBJ}

fclean:		clean
			@rm -f ${NAME} ${OBJ} 

re:			fclean all

clarify: 	clean

.PHONY : fclean all re clean
