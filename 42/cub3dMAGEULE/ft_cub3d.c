/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:14:13 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/18 21:40:26 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 24
#define mapHeight 24
#define txtH 64
#define txtW 64

void reset_image(t_params *params)
{
    int x = 0;
    int y = 0;
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
    
    while(x < (params->screenwidth * params->screenheight))
    {
        params->image->imgdata[x * 4 + y * params->image->sizeline] = r;
        params->image->imgdata[x * 4 + y * params->image->sizeline + 1] = g;
        params->image->imgdata[x * 4 + y * params->image->sizeline + 2] = b;
        x++;
    }
}

void ft_resolution(t_params *params)
{
    char **tmp;
    int i;
    int y = 0;

    i = -1; 
    int res_x;
    int res_y;
    if (!params->res)
        ft_error(ANOMALY_RES);
    tmp = ft_split(params->res, ' ');
    if (tmp[2] || tmp[0] == NULL || tmp[1] == NULL)
        ft_error(ANOMALY_RES);
    //mlx_get_screen_size(params->ray->mlx, &res_x, &res_y);
    params->screenwidth = ft_atoi(tmp[0]);
    params->screenheight = ft_atoi(tmp[1]);
    if (params->screenwidth < 1 || params->screenheight < 1)
        ft_error(ANOMALY_RES);
    //params->screenwidth = params->screenwidth > res_x ? res_x : params->screenwidth;
    //params->screenheight = params->screenheight > res_y ? res_y : params->screenheight;
    return;
}

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
    t_params *params;
    t_ray *ray;
    t_color *color;
    t_image *image;
    t_event *event;
    t_tex *tex;
    t_draw_sprite *sp;
    t_sprite *sprites;
    
    sprites = malloc(sizeof(*sp));
    params = ft_malloc_params();
    color = ft_malloc_color();
    params->color = color;
    search_params(params, fd);
    sp = ft_malloc_sprite(params);
    event = ft_malloc_event();
    image = ft_malloc_image();
    tex = ft_malloc_tex();
    ft_resolution(params);
    ray = ft_malloc_ray(params);
    params->ray = ray;
    params->event = event;
    params->image = image;
    params->tex = tex;
    params->sp = sp;
    params->sprites = sprites;
    ft_get_tex(params);
    //("!\n");
    ft_get_sprite(params, params->textsp);
    //printf("{%d}\n", params->find_pos);
    image->img = mlx_new_image(ray->mlx, params->screenwidth, params->screenheight);
    image->imgdata = mlx_get_data_addr(image->img, &image->bpp, &image->sizeline, &image->endian);
    image->imgsave = mlx_get_data_addr(image->img, &image->bpp, &image->sizeline, &image->endian);
    
    parameters(params, argc, argv);
    if (params->map_find == 0)
        ft_error(NO_MAP);
    if (ft_check_map(params, params->map) == 0)
    ft_error(WRONG_MAP_FORMAT);
    ft_orientation(params, ray);
    ft_getpose_sprite(params->map, sp, sprites);
    ft_getposray(params->map, ray);
    mlx_hook(ray->window, 2, 1L << 0, key_pressed, params);
    mlx_hook(ray->window, 3, 1L << 0, key_released, params);
    mlx_hook(ray->window, 17, 1L << 17, mouse_event, params);
    mlx_loop_hook(ray->mlx, start, params);
    if(!(mlx_loop(ray->mlx) == 0))
        exit(0);
    //ft_free_struct(params);
}
