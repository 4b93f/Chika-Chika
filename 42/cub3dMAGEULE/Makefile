SRCS   = 	srcs/engine/ft_bitmap.c srcs/handle_info/ft_check_map.c srcs/handle_info/ft_check_map2.c srcs/ft_cub3d.c srcs/engine/ft_error.c \
			srcs/handle_info/ft_find_info.c srcs/player/ft_input_key.c srcs/handle_info/ft_map_parsing.c srcs/player/ft_move_player.c \
			srcs/handle_info/ft_parsing_params.c srcs/player/ft_player.c srcs/engine/ft_raycast.c srcs/engine/ft_sprite.c \
 			srcs/struct/ft_struct_bmp.c srcs/struct/ft_struct_color.c srcs/struct/ft_struct_event.c srcs/struct/ft_struct_image.c \
			srcs/struct/ft_struct_params.c srcs/struct/ft_struct_player.c srcs/struct/ft_struct_ray.c srcs/struct/ft_struct_sprite.c \
			srcs/struct/ft_struct_tex.c srcs/engine/ft_textures.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c srcs/struct/ft_struct_spvalues.c \
			srcs/engine/ft_print_sprite.c srcs/engine/ft_print.c srcs/engine/ft_raycast_bis.c srcs/engine/ft_init_game.c \


HEADERS =	cub3d.h
NAME = 		Cub3D

OBJS = 		${SRCS:.c=.o}
MLX = -lmlx -lm -framework OpenGL -framework AppKit

.c.o:
			@${CC} ${CFLAGS} -I ${HEADERS} -c $^ -o ${<:.c=.o}

$(NAME) : $(OBJS)
	@echo "[Remove last version...]"
	@rm -rf Cub3D
	@echo "[Libft compilation...]"
	@$(MAKE) -C ./libft && mv ./libft/libft.a ./includes
	@echo "[Cub3D compilation...]"
	@$(MAKE) -C ./minilibx && mv ./minilibx/libmlx.dylib ../cub3dMAGEULE
	@echo "[Minilibx compilation...]"
	@gcc -Wall -Wextra -Werror $(MLX) $(OBJS) libmlx.dylib ./includes/libft.a -I./usr/include -o $(NAME)
	@echo "[Done !]"


all:		${NAME}
	
clean:	
			@rm -f ${OBJS} ${OBJS}


fclean:		clean
			@rm -f ${NAME} ${OBJS}
			@echo "[Remove libft...]"
			@$(MAKE) -C libft fclean
			@rm -f ./includes/libft.a
			@echo "[Remove minilibx...]"
			@$(MAKE) -C minilibx clean
			@rm -f libmlx.dylib
			@echo "[Done!]"


clarify:
			@echo "[Clean cub3d.o ...]"
			@rm -f ${OBJS}
			@echo "[Clean libft.o ...]"
			@$(MAKE) -C libft clarify
			@echo "[Clean minilib.o ...]"
			@$(MAKE) -C minilibx clarify



re:			fclean all clarify


.PHONY : fclean all re clean clarify