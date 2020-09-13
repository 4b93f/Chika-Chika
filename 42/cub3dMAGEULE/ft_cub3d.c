/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:14:13 by chly-huc          #+#    #+#             */
/*   Updated: 2020/09/13 19:39:26 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 600
#define screenHeight 900

void    ft_mlx_pixel_to_image(t_params *params)
{
    int bpp;
    int sizeline;
    int endian;
    void *img;
    char *imgdata;
    unsigned char r = 0;

    img = mlx_new_image(params->ray->mlx, 1000, 1000);
    imgdata = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
    while (x < params->screenwidth)
    {
        imgdata[x * 1000 + y] = r;
        imgdata[x * 1000 + y + 1] = r;
        imgdata[x * 1000 + y + 2] = r;
    }
    mlx_put_image_to_window(mlx, window, img, 0,0);

}

void reset_window(t_params *params)
{
    int i = -1;
    int j = -1;
    while(++i <= params->screenwidth)
    {
        while(++j <= params->screenheight)
            mlx_pixel_put(params->ray->mlx, params->ray->window, i, j, 0);
        j = 0;
    }
}

void ft_error()
{
    printf("error\n");
    exit(0);
}

void ft_resolution(t_params *params)
{
    char **tmp;
    
    tmp = ft_split(params->res, ' ');
    params->screenwidth = ft_atoi(tmp[0]);
    params->screenheight = ft_atoi(tmp[1]);
    return;
}

void AVANCE(t_params *params)
{
    if(params->map[(int)(params->ray->posX + params->ray->dirX * params->ray->movespeed)][(int)params->ray->posY])
        params->ray->posX += params->ray->dirX * params->ray->movespeed;
    if(params->map[(int)params->ray->posX][(int)(params->ray->posY + params->ray->dirY * params->ray->movespeed)])
        params->ray->posY += params->ray->dirY * params->ray->movespeed;
    reset_window(params);
}

void RECULE(t_params *params)
{
    if(params->map[(int)(params->ray->posX - params->ray->dirX * params->ray->movespeed)][(int)params->ray->posY])
         params->ray->posX -= params->ray->dirX * params->ray->movespeed;
    if(params->map[(int)params->ray->posX][(int)(params->ray->posY - params->ray->dirY * params->ray->movespeed)])
        params->ray->posY -= params->ray->dirY * params->ray->movespeed;
    reset_window(params);
}

void GAUCHE(t_params *params)
{
    double olddirx;
    double oldplanex;
    olddirx = params->ray->dirX;
    oldplanex = params->ray->planeX;

    params->ray->dirX =  params->ray->dirX * cos(-params->ray->rotspeed) - params->ray->dirY * sin (-params->ray->rotspeed);
    params->ray->dirY = olddirx * sin(-params->ray->rotspeed) + params->ray->dirY * cos(-params->ray->rotspeed);
    params->ray->planeX = params->ray->planeX * cos(-params->ray->rotspeed) - params->ray->planeY * sin(-params->ray->rotspeed);
    params->ray->planeY = oldplanex * sin(-params->ray->rotspeed) + params->ray->planeY * cos(-params->ray->rotspeed);
    reset_window(params);
}

void DROITE(t_params *params)
{
    double olddirx;
    double oldplanex;
    olddirx = params->ray->dirX;
    oldplanex = params->ray->planeX;

    params->ray->dirX =  params->ray->dirX * cos(params->ray->rotspeed) - params->ray->dirY * sin (params->ray->rotspeed);
    params->ray->dirY = olddirx * sin(params->ray->rotspeed) + params->ray->dirY * cos(params->ray->rotspeed);
    params->ray->planeX = params->ray->planeX * cos(params->ray->rotspeed) - params->ray->planeY * sin(params->ray->rotspeed);
    params->ray->planeY = oldplanex * sin(params->ray->rotspeed) + params->ray->planeY * cos(params->ray->rotspeed);
    reset_window(params);
}


int key_pressed(int key, void *params)
{
    if (key == 13)
    {
        AVANCE(params);
    }
    if (key == 0)
    {
        printf("A\n");
        GAUCHE(params);
    }
    if (key == 1)
    {
        RECULE(params);
    }
    if (key == 2)
    {
        printf("D\n");
        DROITE(params);
    }
    if (key == 53)
        exit(0); 
    return(0);
}

int start(t_params *params)
{
    ft_raycast(params, params->ray, params->color);
    return(1);
}

void ft_getposray(char **map, t_ray *ray)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
            {
                ray->posX = i;
                ray->posY = j;
            }
            j++;
        }
        j = 0;
        i++;
    }    
}

int main(int argc, char **argv)
{
    if (argc != 2)
        exit(0);
    int fd;
    fd = open(argv[1], O_RDONLY);
    t_params *params;
    t_ray *ray;
    t_color *color;
    
    params = ft_malloc_params();
    color = ft_malloc_color();

    if (search_params(params, fd) == 0)
        ft_error();
    ft_resolution(params);
    ray = ft_malloc_ray(params);
    params->color = color;
    params->ray = ray;
    if (params->map_find == 0)
        ft_error();
    if (ft_check_map(params->map) == 0)
        ft_error();
    ft_getposray(params->map, ray);
    mlx_hook(ray->window, 2, 1L << 0, key_pressed, params);
    mlx_put_image_to_window()
    mlx_loop_hook(ray->mlx, start, params);
    mlx_loop(ray->mlx);
    //ft_free_struct(params);
}
