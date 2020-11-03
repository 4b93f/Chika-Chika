/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:49:25 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/03 21:30:30 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#define TXTH 64
#define TXTW 64

# include "../minilibx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

enum					e_bool
{
	FALSE,
	TRUE
};

enum					e_error
{
	NO_MAPFILE,
	WRONG_PARAMS,
	NO_MAP,
	MALLOC_ERROR,
	DUPLICATE_PARAMETERS,
	ANOMALY_TEXTURES,
	RGB_ERROR,
	RGB_MISSING,
	WRONG_CHAR_IN_RGB,
	ANOMALY_RES,
	PLAYER_NOT_FOUND,
	ANOMALY_SPRITE,
	SOMETHING_IS_MISSING,
	WRONG_MAP_FORMAT,
	ERROR_ARGUMENT,
};

typedef struct			s_bmp
{
	int				fd;
	int				img_height;
	int				img_width;
	int				imgsize;
	int				bytes_in_width;
	char			*filetype;
	unsigned int	headersize;
	unsigned int	bpp;
	unsigned int	planes;
	unsigned int	img_size;
	unsigned int	pixeldataoffset;
	unsigned int	filesize;
}						t_bmp;

typedef	struct			s_color
{
	int				a;
	int				r;
	int				g;
	int				b;
	int				cell_r;
	int				cell_g;
	int				cell_b;
	int				cell_index;
	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				floor_index;
}						t_color;

typedef struct			s_event
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			turn_left;
	int			turn_right;
}						t_event;

typedef struct			s_image
{
	int			bpp;
	int			sizeline;
	int			endian;
	int			img_width;
	int			img_height;
	int			save;
	void		*img;
	char		*imgdata;
	char		*imgsave;
}						t_image;

typedef struct			s_player
{
	double posx;
	double posy;
	double dirx;
	double diry;
	double planex;
	double planey;
	double rotspeed;
	double movespeed;
	double camx;
}						t_player;

typedef struct			s_ray
{
	int			width;
	int			mapy;
	int			mapx;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	void		*mlx;
	void		*window;
}						t_ray;

typedef struct			s_tex
{
	void		*texture;
	char		*texturedata;
	int			bpp;
	int			sizeline;
	int			endian;
	int			tex_width;
	int			tex_height;
	int			texnum;
	double		texpos;
	int			texx;
	int			texy;
	double		step;
	char		**tex;

}						t_tex;

typedef struct			s_sprite
{
	int			x;
	int			y;
}						t_sprite;

typedef struct			s_sprites
{
	struct s_sprite		*next;
}						t_sprites;

typedef struct			s_draw_sprite
{
	t_sprite	*sprites;
	int			bpp;
	int			sizeline;
	int			endian;
	int			*pos_sprite;
	int			numsprite;
	int			sp_width;
	int			sp_height;
	double		x;
	double		y;
	void		*mlx_sprite;
	char		*spdata;
	char		**sp;
}						t_draw_sprite;

typedef struct			s_spvalues
{
	int			y;
	int			j;
	double		invdet;
	double		transformx;
	double		transformy;
	int			sprite_screenx;
	int			sprite_height;
	int			sprite_width;
	int			drawstartx;
	int			drawstarty;
	int			drawendx;
	int			drawendy;
	int			x;
	int			spx;
	int			spy;
	t_sprite	tmp;
}						t_spvalues;

typedef struct			s_params
{
	int				map_find;
	int				find_pos;
	int				player_orientation;
	int				screenwidth;
	int				screenheight;
	char			*res;
	char			*textno;
	char			*textso;
	char			*textwe;
	char			*textea;
	char			*textsp;
	char			*colorf;
	char			**argbcolorf;
	char			*colorc;
	char			**argbcolorc;
	char			**map;
	t_ray			*ray;
	t_color			*color;
	t_event			*event;
	t_image			*image;
	t_tex			*tex;
	t_draw_sprite	*sp;
	t_sprite		*sprites;
	t_player		*player;
	t_bmp			*bmp;
	t_spvalues		*sv;
}						t_params;

int				ft_check_map(t_params *params, char **map);
int				ft_check_startend(char *str);
int				ft_updownwall(char *map);
int				ft_check_char(t_params *params, char *map);
int				ft_check_space(char **map);
int				ft_isspace(int c);
int				find_duplicate(char *str, int c);
int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
int				ft_isdigit(int c);
int				search_params(t_params *params, int fd);
int				numsprite(char **map);
int				key_pressed(int key_pressed, t_params *params);
int				key_released(int key_released, t_params *params);
int				ft_printf(const char *str, ...);
char			*ft_strdup(const char *s);
char			**ft_realloc(char **str, char *line);
char			**ft_map_parsing(int fd, char *firstline);
void			key_event(t_params *params);
void			ft_getposray(char **map, t_player *player);
void			up(t_params *params);
void			down(t_params *params);
void			left(t_params *params);
void			reset_image(t_params *params);
void			ft_getpose_sprite(char **map, t_draw_sprite *sp,
		t_sprite *sprites);
void			right(t_params *params);
void			turn_right(t_params *params);
void			turn_left(t_params *params);
void			reset_image(t_params *params);
void			ft_free_struct(t_params *to_free);
void			save(t_params *params);
void			cut(char *s);
void			ft_error(int num);
void			ft_raycast(t_params *params, t_ray *ray, t_color *color);
void			ft_get_tex(t_params *params);
void			ft_pixel_to_image(int x, int y, t_params *params);
void			ft_orientation(t_params *params, t_ray *ray);
void			ft_get_sprite(t_params *params, char *path);
void			parameters(t_params *params, int argc, char **argv);
void			ft_void_algo(int *i, int *j, int *k, char **map);
void			ft_zero_algo(int *i, int *j, int *k, char **map);
void			get_next_value_bis(t_params *params, int x,
		double wallx, int *y);
void			cut(char *s);
void			ft_init_game(t_params *params, int fd);
void			print_cell_floor(t_params *params, t_color *color, int x);
void			print_wall(t_params *params, int x, int y);
void			ft_sprite_to_image(t_params *params);
void			sprite(t_params *params, double *zbuffer);
void			ft_resolution(t_params *params);
void			ft_check_floor(t_params *params);
void			ft_check_cell(t_params *params);
void			format_color(t_params *params);
t_params		*ft_malloc_params(void);
t_spvalues		*ft_malloc_spvalues();
t_ray			*ft_malloc_ray(t_params *params);
t_color			*ft_malloc_color(void);
t_image			*ft_malloc_image(void);
t_event			*ft_malloc_event(void);
t_draw_sprite	*ft_malloc_sprite(t_params *params);
t_player		*ft_malloc_player(void);
t_tex			*ft_malloc_tex();
t_bmp			*ft_malloc_bmp(t_params *params);

#endif