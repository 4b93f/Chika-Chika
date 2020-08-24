/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:50:31 by becentrale        #+#    #+#             */
/*   Updated: 2020/08/22 00:10:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_resolution(t_params *params)
{
    char **tmp;
    
    tmp = ft_split(params->res, ' ');
    params->screenwidth = ft_atoi(tmp[0]);
    params->screenheight = ft_atoi(tmp[1]);
    return;
}

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


void ft_raycast(t_params *params,t_ray *ray)
{
    int x;

    x = 0;
    ft_resolution(params);
    ft_getposplayer(params->map, ray);
    
    ray->camX = 2 * x / (double)(ray->width) - 1;
    ray->raydirX = ray->dirX + ray->planeX * ray->camX;
    ray->raydirY = ray->dirY + ray->planeY * ray->camX;
    ray->mapX = (int)ray->posX;
    ray->mapY = (int)ray->posY;
    ray->deltadistX = (ray->raydirY == 0) ? 0 : ((ray->raydirX == 0) ? 1 : abs(1 / ray->raydirX));
    ray->deltadistY = (ray->raydirX == 0) ? 0 : ((ray->raydirY == 0) ? 1 : abs(1 / ray->raydirY));
    
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
        if (params->map > 0) 
            ray->hit = 1;
    }

    if (ray->side == 0)
            ray->perpwalldist = (ray->mapX - ray->posX + (1 - ray->stepX) / 2) / ray->raydirX;
    else
        ray->perpwalldist = (ray->mapY - ray->posY + (1 - ray->stepY) / 2) / ray->raydirY;
    
    ray->lineheight = (int)(params->screenheight / ray->perpwalldist);
    ray->drawstart = -(ray->lineheight)  / 2 + (int)params->screenheight / 2;
    if (ray->drawstart < 0)
        ray->drawstart = 0;
    ray->drawend = ray->lineheight / 2 + (int)params->screenheight / 2;
    if (ray->drawend >= params->screenheight)
        ray->drawend = params->screenheight - 1;
    
    return;    
}