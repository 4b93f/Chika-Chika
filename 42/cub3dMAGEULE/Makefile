SRCS   = 	srcs/ft_bitmap.c srcs/ft_check_map.c srcs/ft_check_map2.c srcs/ft_cub3d.c srcs/ft_error.c srcs/ft_find_info.c srcs/ft_input_key.c \
			srcs/ft_map_parsing.c srcs/ft_move_player.c srcs/ft_parsing_params.c srcs/ft_player.c srcs/ft_raycast.c srcs/ft_sprite.c \
 			srcs/ft_struct_bmp.c srcs/ft_struct_color.c srcs/ft_struct_event.c srcs/ft_struct_image.c srcs/ft_struct_params.c srcs/ft_struct_player.c \
			srcs/ft_struct_ray.c srcs/ft_struct_sprite.c srcs/ft_struct_tex.c srcs/ft_textures.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \


HEADERS =	cub3d.h
NAME = 		Cub3D

OBJS = 		${SRCS:.c=.o}
MLX = -lmlx -lm -framework OpenGL -framework AppKit

.c.o:
			${CC} ${CFLAGS} -I ${HEADERS} -c $^ -o ${<:.c=.o}

$(NAME) : $(OBJS)
	@echo "\033[33m[Remove last version...]"
	@rm -rf Cub3D
	@echo "\033[33m[Libft compilation...]"
	@$(MAKE) -C ./libft && mv ./libft/libft.a ./includes
	@echo "\033[33m[Cub3D compilation...]"
	@$(MAKE) -C ./minilibx && mv ./minilibx/libmlx.dylib ./srcs
	@echo "\033[33m[Minilibx compilation...]"
	@gcc -Wall -Wextra -Werror $(MLX) $(OBJS) ./includes/libft.a -I./usr/include -o $(NAME)
	@echo "\033[33m[Done !]"


all:		${NAME} 
	
clean:	
			rm -f ${OBJS} ${OBJ}

fclean:		clean
			rm -f ${NAME} ${OBJ}

clarify:
			mkdir ./srcs/temp && rm -f ${OBJS}

re:			fclean all

.PHONY : fclean all re clean