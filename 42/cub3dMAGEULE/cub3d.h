/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:49:25 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/16 19:07:28 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

enum e_bool
{
  FALSE,
  TRUE
}; 

enum e_error
{
  NO_MAPFILE,
  WRONG_PARAMS,
  NO_MAP,
  MALLOC_ERROR,
  DUPLICATE_PARAMETERS,
  ANOMALY_TEXTURES,
  RGB_ERROR,
  RGB_MISSING,
  ANOMALY_RES,
  PLAYER_NOT_FOUND,
  ANOMALY_SPRITE,
  SOMETHING_IS_MISSING
};

typedef struct s_color
{
  unsigned char a;
  int r;
  int g;
  int b;
  int cell_r;
  int cell_g;
  int cell_b;
  int floor_r;
  int floor_g;
  int floor_b;
}               t_color;

typedef struct s_bmp
{
  int fd;
  int img_height;
  int img_width;
  char *filetype;
  unsigned int headersize;
  unsigned int bpp;
  int bytes_int_width;
  unsigned int planes;
  unsigned int img_size;
  unsigned int pixeldataoffset;
  unsigned int filesize;
}              t_bmp;

typedef struct s_event
{
  int up;
  int down;
  int turn_left;
  int turn_right;
  int left;
  int right;  
}              t_event;

typedef struct s_ray
{
  int width;
  int mapY;
  int mapX;
  int stepX;
  int stepY;
  int hit;
  int side;
  int lineheight;
  int drawstart;
  int drawend;
  double rotspeed;
  double movespeed;
  double posX;
  double posY;
  double dirX;
  double dirY;
  double planeX;
  double planeY;
  double raydirX;
  double raydirY;
  double camX;
  double sidedistX; // distance entre ray et prochain axe Y//
  double sidedistY; // distance entre ray et prochain axe X//
  double deltadistX; // distance entre le 1er axe X et le 2eme //
  double deltadistY;  // distance entre le 1er axe Y et le 2eme //
  double perpwalldist;
  void *mlx;
  void *window;
}               t_ray;

typedef struct s_image
{
  int bpp;
  int sizeline;
  int endian;
  int img_width;
  int img_height;
  void *img;
  char *imgdata;

  int save;
  char *imgsave;
  
}               t_image;

typedef struct s_tex
{
  int bpp;
  int sizeline;
  int endian;
  int tex_width;
  int tex_height;
  char **tex;
}               t_tex;

typedef struct s_sprite
{
  int x;
  int y;
}               t_sprite;

typedef struct s_sprites
{
  int x;
  int y;
  struct s_sprite *next;
}              t_sprites;

typedef struct s_draw_sprite
{
  t_sprite *sprites;
  int bpp;
  int *pos_sprite;
  int sizeline;
  int endian;
  int numsprite;
  int sp_width;
  int sp_height;
  double x;
  double y;
  void *test;
  void *lol;
  char *spdata;
  char *testdata;
  char **sp;
}              t_draw_sprite;

typedef struct s_params
{
  int map_find;
  int find_pos;
  int player_orientation;
  int screenwidth;
  int screenheight;
  char *res;
  char *textno;
  char *textso;
  char *textwe;
  char *textea;
  char *textsp;
  char *textp;
  char *textf;
  char *colorf;
  char **argbcolorf;
  char *colorc;
  char **argbcolorc;
  char **map;
  t_ray *ray;
  t_color *color;
  t_event *event;
  t_image *image;
  t_tex *tex;
  t_draw_sprite *sp;
  t_sprite *sprites;
}              t_params;

int ft_check_map(t_params *params,char **map);
int ft_check_startend(char *str);
int  ft_updownwall(char *map);
int ft_check_char(t_params *params, char *map);
int ft_check_space(char **map);
int		ft_isdigit(int c);
int search_params(t_params *params, int fd);
int numsprite(char **map);
int key_pressed(int key_pressed, t_params *params);
int key_released(int key_released, t_params *params);
void key_event(t_params *params);
void ft_getposray(char **map, t_ray *ray);
char	*ft_strdup(const char *s);
char **ft_realloc(char **str, char *line);
char **ft_map_parsing(int fd, char *firstline);
void up(t_params *params);
void down(t_params *params);
void left(t_params *params);
void ft_getpose_sprite(char **map, t_draw_sprite *sp, t_sprite *sprites);
void right(t_params *params);
void turn_right(t_params *params);
void turn_left(t_params *params);
void reset_image(t_params *params);
void ft_free_struct(t_params *to_free);
void save(t_params *params);
void ft_error(int num);
void ft_raycast(t_params *params,t_ray *ray, t_color *color);
void ft_get_tex(t_params *params);
void DROITE(t_params *params);
void ft_pixel_to_image(int x, int y, t_params *params);
void ft_orientation(t_params *params, t_ray *ray);
void ft_get_sprite(t_params *params, char *path);
t_params *ft_malloc_params();
t_ray *ft_malloc_ray();
t_color *ft_malloc_color();
t_image *ft_malloc_image();
t_event *ft_malloc_event();
t_draw_sprite *ft_malloc_sprite(t_params * params);
t_tex *ft_malloc_tex();

#endif