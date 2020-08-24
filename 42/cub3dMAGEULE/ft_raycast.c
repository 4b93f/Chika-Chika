/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becentrale <becentrale@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:50:31 by becentrale        #+#    #+#             */
/*   Updated: 2020/08/24 18:33:55 by becentrale       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_getposplayer(char **map, t_ray *ray)
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

void verline(int x, int drawstart, int drawend, t_ray *ray)
{
    while (drawstart < drawend)
    {
        mlx_pixel_put(ray->mlx, ray->window, x, drawstart, 65030);
        drawstart++;
    }
}

void ft_raycast(t_params *params,t_ray *ray, t_color *color)
{
    int x;

    x = -1;
    ft_getposplayer(params->map, ray);
    while(++x < params->screenwidth)
    {
        //printf("!\n");
        ray->camX = 2 * x / (double)(params->screenwidth) - 1;
        ray->raydirX = ray->dirX + ray->planeX * ray->camX;
        ray->raydirY = ray->dirY + ray->planeY * ray->camX;
        //printf("{%f}{%f}\n", ray->raydirX, ray->raydirX);
        ray->mapX = (int)ray->posX;
        ray->mapY = (int)ray->posY;
        ray->deltadistX = fabs(1 / ray->raydirX);
        ray->deltadistY = fabs(1 / ray->raydirY);
        
        // Direction ray
        if (ray->raydirX < 0)
        {
            ray->stepX = -1;
            ray->sidedistX = (ray->posX - ray->mapX) * ray->deltadistX;
        }
        else
        {
            ray->stepX = 1;
            ray->sidedistX = (ray->mapX + 1.0 - ray->posX) * ray->deltadistX;
        }   
        if (ray->raydirY < 0)
        {
            ray->stepY = - 1;
            ray->sidedistY = (ray->posY - ray->mapY) * ray->deltadistY;
        }
        else
        {
            ray->stepY = 1;
            ray->sidedistY = (ray->mapY + 1.0 - ray->posY) * ray->deltadistY;
        }
        
        while (ray->hit == 0)
        {
            if (ray->sidedistX < ray->sidedistY)
            {
                ray->sidedistX += ray->deltadistX;
                ray->mapX += ray->stepX;
                ray->side = 0;
            }
            else
            {
                ray->sidedistY += ray->deltadistY;
                ray->mapY += ray->stepY;
                ray->side = 1;
            }
            if (params->map[ray->mapX][ray->mapY] > 0) 
                ray->hit = 1;
        }
        printf("%d", ray->mapY);
        if (ray->side == 0)
            ray->perpwalldist = (ray->mapX - ray->posX + (1 - ray->stepX) / 2) / ray->raydirX;
        else
            ray->perpwalldist = (ray->mapY - ray->posY + (1 - ray->stepY) / 2) / ray->raydirY;
        //printf("{%d}{%f}{%d}{%f}\n", ray->mapY, ray->posY, ray->stepY, ray->raydirY);
        //printf("perp wall = %f\n", ray->perpwalldist);
        ray->lineheight = (int)(params->screenheight / ray->perpwalldist);
        ray->drawstart = (-ray->lineheight / 2 + (params->screenheight / 2));
        if (ray->drawstart < 0)
            ray->drawstart = 0;
        ray->drawend = ray->lineheight / 2 + (int)params->screenheight / 2;
        //printf("drawEnd == [%d]\n", ray->drawend);
        if (ray->drawend >= params->screenheight)
            ray->drawend = params->screenheight - 1;
        if(params->map[ray->mapX][ray->mapY] == 1)
            color->r = 255;
        if(params->map[ray->mapX][ray->mapY] == 2)
            color->g = 255;
        if(params->map[ray->mapX][ray->mapY] == 3)
            color->b = 255;
        ray->side == 1 ? color->colors /=  2 : 0;
        //printf("drawStart == [%d]\n", ray->drawstart);
        //printf("hit == [%d]\n", ray->hit);
        //verline(x, ray->drawstart, ray->drawend, ray);
    }    
    return;    
}