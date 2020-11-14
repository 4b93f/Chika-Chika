ls
SRCS   = 	


HEADERS =	cub3d.h
NAME = 		Cub3D
FLAGS = -Wall -Wextra -Werror
OBJS = 		${SRCS:.c=.o}
MLX = -lmlx -lm -framework OpenGL -framework AppKit
LIB = ./lib/libft.a ./lib/libftprintf.a libmlx.dylib
CC = gcc

.c.o:
			@${CC} -g ${FLAGS} -I ${HEADERS} -c $^ -o ${<:.c=.o}

$(NAME) : $(OBJS)
	@echo "[Remove last version...]"
	@rm -rf Cub3D
	@echo "[Libft compilation...]"
	@$(MAKE) -C ./libft && cp ./libft/libft.a ./lib && cp ./libft/libft.h ./includes
	@echo "[ft_printf compilation...]"
	@$(MAKE) -C ./ft_printf && cp ./ft_printf/libftprintf.a ./lib && cp ./ft_printf/ft_printf.h ./includes
	@echo "[Minilibx compilation...]"
	@$(MAKE) -C ./minilibx && cp ./minilibx/libmlx.dylib ../cub3dMAGEULE && cp ./minilibx/mlx.h ./includes 
	@echo "[Cub3D compilation...]"
	@${CC} ${FLAGS} $(MLX) $(OBJS) ${LIB} -o $(NAME)
	@echo "[Done !]"


all:		${NAME}
	
clean:	
			@rm -f ${OBJS} ${OBJS}


fclean:		clean
			@rm -f ${NAME} ${OBJS}
			@echo "[Remove libft...]"
			@$(MAKE) -C libft fclean
			@echo "[Remove ft_printf...]"
			@$(MAKE) -C ft_printf fclean
			@echo "[Remove minilibx...]"
			@$(MAKE) -C minilibx clean
			@rm -rf libmlx.dylib ./lib/libft.a ./lib/libftprintf.a
			@rm -rf ./includes/libft.h ./includes/ft_printf.h ./includes/mlx.h
			@echo "[Done!]"


clarify:
			@echo "[Clean cub3d.o ...]"
			@rm -f ${OBJS}
			@echo "[Clean libft.o ...]"
			@$(MAKE) -C libft clarify
			@echo "[Clean ft_printf.o ...]"
			@$(MAKE) -C ft_printf clarify
			@echo "[Clean minilib.o ...]"
			@$(MAKE) -C minilibx clarify



re:			fclean all


.PHONY : fclean all re clean clarify