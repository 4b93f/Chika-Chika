SRCS   = 	ft_check_map.c ft_cub3d.c ft_map_parsing.c ft_raycast.c \
			ft_struct_color.c ft_struct_event.c ft_struct_image.c   \
			ft_struct_event.c ft_struct_ray.c ft_struct_params.c    \
			ft_parsing_params.c


HEADERS =	cub3d.h
NAME = 		cub3d
OBJS = 		${SRCS:.c=.o}

.c.o:
			${CC} ${CFLAGS} -I ${HEADERS} -c $^ -o ${<:.c=.o}

${NAME}: 	${OBJS}
			gcc -o ${NAME} ${OBJS} minilibx/libmlx.a

all:		${NAME}
	
clean:	
			rm -f ${OBJS} ${OBJ}

fclean:		clean
			rm -f ${NAME} ${OBJ}

re:			fclean all

.PHONY : fclean all re clean