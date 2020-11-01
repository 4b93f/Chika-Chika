/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:14:13 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/01 18:34:35 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 24
#define mapHeight 24
#define txtH 64
#define txtW 64

int mouse_event(t_params *params)
{
    exit(0);
}

int start(t_params *params)
{
    //printf("!!!!!\n");
    ft_raycast(params, params->ray, params->color);
    if (params->image->save == 1)
        save(params);
    mlx_put_image_to_window(params->ray->mlx, params->ray->window, params->image->img, 0,0);
    key_event(params);
    return(1);
}

int main(int argc, char **argv)
{
    int fd;
    
    fd = open(argv[1], O_RDONLY);
	t_player *player;
    t_params *params;
    t_ray *ray;
    t_color *color;
    t_image *image;
    t_event *event;
    t_tex *tex;
    t_draw_sprite *sp;
    t_sprite *sprites;
	t_bmp *bmp;
	t_spvalues *sv;

    parameters(params, argc, argv);
    params = ft_malloc_params();
	player = ft_malloc_player();
    color = ft_malloc_color();
    params->color = color;
    sprites = malloc(sizeof(*sp));
	
	
    search_params(params, fd);
    sp = ft_malloc_sprite(params);
	sv = ft_malloc_spvalues();
    event = ft_malloc_event();
    image = ft_malloc_image();
    tex = ft_malloc_tex();
    ft_resolution(params);
	bmp = ft_malloc_bmp(params);
	params->bmp = bmp;
    ray = ft_malloc_ray(params);
    params->ray = ray;
	params->sv = sv;
	params->player = player;
    params->event = event;
    params->image = image;
    params->tex = tex;
    params->sp = sp;
    params->sprites = sprites;
    ft_get_tex(params);
    ft_get_sprite(params, params->textsp);
    image->img = mlx_new_image(ray->mlx, params->screenwidth, params->screenheight);
    image->imgdata = mlx_get_data_addr(image->img, &image->bpp, &image->sizeline, &image->endian);
    image->imgsave = mlx_get_data_addr(image->img, &image->bpp, &image->sizeline, &image->endian);
    
    if (params->map_find == 0)
        ft_error(NO_MAP);
    if (ft_check_map(params, params->map) == 0)
    ft_error(WRONG_MAP_FORMAT);
    ft_orientation(params, ray);
    ft_getpose_sprite(params->map, sp, sprites);
    ft_getposray(params->map, player);
    mlx_hook(ray->window, 2, 1L << 0, key_pressed, params);
    mlx_hook(ray->window, 3, 1L << 0, key_released, params);
    mlx_hook(ray->window, 17, 1L << 17, mouse_event, params);
    mlx_loop_hook(ray->mlx, start, params);
    if(!(mlx_loop(ray->mlx) == 0))
        exit(0);
    //ft_free_struct(params);
}
