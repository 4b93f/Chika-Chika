/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:14:13 by chly-huc          #+#    #+#             */
/*   Updated: 2020/09/16 23:52:32 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 600
#define screenHeight 900
#define txtH 64
#define txtW 64

void reset_image(t_params *params)
{
    int x = 0;
    int y = 0;
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
    
    while(x < (600 * 900))
    {
        params->image->imgdata[x * 4 + y * params->image->sizeline] = r;
        params->image->imgdata[x * 4 + y * params->image->sizeline + 1] = g;
        params->image->imgdata[x * 4 + y * params->image->sizeline + 2] = b;
        x++;
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
   reset_image(params);
}

void RECULE(t_params *params)
{
    if(params->map[(int)(params->ray->posX - params->ray->dirX * params->ray->movespeed)][(int)params->ray->posY])
         params->ray->posX -= params->ray->dirX * params->ray->movespeed;
    if(params->map[(int)params->ray->posX][(int)(params->ray->posY - params->ray->dirY * params->ray->movespeed)])
        params->ray->posY -= params->ray->dirY * params->ray->movespeed;
   reset_image(params);
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
    reset_image(params);
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
    reset_image(params);
    
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
    mlx_put_image_to_window(params->ray->mlx, params->ray->window, params->image->img, 0,0);
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


void test(t_params *params)
{
    int textnum = params->map[params->ray->mapX][params->ray->mapY] - 1;
    double wallx;
    if(params->ray->side == 0)
        wallx = params->ray->posY + params->ray->perpwalldist * params->ray->raydirY;
    else
        wallx = params->ray->posX + params->ray->perpwalldist * params->ray->raydirX;
    wallx -= round(wallx);

    int texx = (int)wallx * (double)txtH;
    if (params->ray->side == 0 && params->ray->raydirX > 0)
        texx = txtW - texx -1;
    if (params->ray->side == 1 && params->ray->raydirY < 0)
        texx = txtW - texx - 1;


    int y = params->ray->drawstart - 1;
    double step = 1.0 * txtH / params->ray->lineheight;
    double texpos = (params->ray->drawstart - params->screenheight / 2 + params->ray->lineheight / 2) * step;
    while(++y < params->ray->drawend)
    {
        int texy = (int)texpos & (txtH - 1);
        texpos += step;
        unsigned int color = texture[textnum][txtH * texy + texx];
        if (params->ray->side == 1)
            color = (color >> 1) & 8355711;
            buffer[y][x] = color;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        exit(0);
    int fd;
    int bpp;
    int sizeline;
    int endian;
    fd = open(argv[1], O_RDONLY);
    t_params *params;
    t_ray *ray;
    t_color *color;
    t_image *image;
    
    params = ft_malloc_params();
    color = ft_malloc_color();
    if (search_params(params, fd) == 0)
        ft_error();
    ft_resolution(params);
    ray = ft_malloc_ray(params);
    params->color = color;
    params->ray = ray;
    image = ft_malloc_image();
    image->img = mlx_new_image(ray->mlx, 900, 600);
    image->imgdata = mlx_get_data_addr(image->img, &image->bpp, &image->sizeline, &image->endian);
    params->image = image;
    if (params->map_find == 0)
        ft_error();
    if (ft_check_map(params->map) == 0)
        ft_error();
    ft_getposray(params->map, ray);
    mlx_hook(ray->window, 2, 1L << 0, key_pressed, params);
    mlx_loop_hook(ray->mlx, start, params);
    mlx_loop(ray->mlx);
    //ft_free_struct(params);
}
