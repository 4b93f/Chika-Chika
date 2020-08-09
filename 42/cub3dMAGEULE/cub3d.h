/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:49:25 by chly-huc          #+#    #+#             */
/*   Updated: 2020/08/09 01:03:53 by root             ###   ########.fr       */
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
# define TRUE 1
# define FALSE 0
# define WRONG_MAP 0
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126


typedef struct  s_keys
{
  int			left:1;
	int			right:1;
	int			down:1;
	int			up:1;
}               t_keys;

typedef struct s_color
{
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char colors;
}               t_color;


typedef struct s_struct
{
  int w;
  int mapY;
  int mapX;
  int stepX;
  int stepY;
  int hit;
  int side;
  int lineheight;
  int drawstart;
  int drawend;
  int movespeed;
  int rotspeed;
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
  t_color color;
}               t_struct;

typedef struct s_params
{
  int resx;
  int resy;
  char *textno;
  char *textso;
  char *textwe;
  char *textea;
  char *textsp;
  char *textp;
  char *textc;
  char **map;
}              t_params;


void *ft_realloc(void *ptr, int new_size);
char	*ft_strdup(const char *s);
char **final_pars(int fd);
void parse_params(t_struct *params);
char **ft_map_parsing(char *path);
t_params *ft_malloc_struct(char *path);
void ft_free_struct(t_params *to_free);
int ft_check_map(char **map);
void ft_error(void);
int		ft_isdigit(int c);

#endif