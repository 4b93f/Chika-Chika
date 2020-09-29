/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:50:31 by becentrale        #+#    #+#             */
/*   Updated: 2020/09/29 17:07:14 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define txtH 64
#define txtW 64
#include "cub3d.h"

void ft_pixel_to_image(int x, int y, t_params *params)
{
    unsigned char a = 100;
    unsigned char r = 255;
    unsigned char g = 0;
    unsigned char b = 0;
    params->image->imgdata[x * 4 + y * params->image->sizeline] = a;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 1] = r;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 2] = g;
    params->image->imgdata[x * 4 + y * params->image->sizeline + 3] = b;
    params->image->imgsave[x * 4 + y * params->image->sizeline] = a;
    params->image->imgsave[x * 4 + y * params->image->sizeline + 1] = r;
    params->image->imgsave[x * 4 + y * params->image->sizeline + 2] = g;
    params->image->imgsave[x * 4 + y * params->image->sizeline + 3] = b;
}

void verline(int x, int drawstart, int drawend, t_params *params)
{
    while (++drawstart <= drawend)
        ft_pixel_to_image(x, drawstart, params);
}


void ft_raycast(t_params *params,t_ray *ray, t_color *color)
{
    int x;

    x = 0;
    while(++x < params->screenwidth)
    {
        ray->hit = 0;
        ray->camX = (2 * x) / (double)(params->screenwidth) - 1;
        ray->raydirX = ray->dirX + ray->planeX * ray->camX;
        ray->raydirY = ray->dirY + ray->planeY * ray->camX;
        ray->mapX = (int)ray->posX;
        ray->mapY = (int)ray->posY;
        ray->deltadistX = (ray->raydirY == 0) ? 0 : ((ray->raydirX == 0) ? 1 : fabs(1 / ray->raydirX));
        ray->deltadistY = (ray->raydirX == 0) ? 0 : ((ray->raydirY == 0) ? 1 : fabs(1 / ray->raydirY));
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
            if (params->map[ray->mapX][ray->mapY] == '1') 
                ray->hit = 1;
        }
        if (ray->side == 0)
            ray->perpwalldist = (ray->mapX - ray->posX + (1 - ray->stepX) / 2) / ray->raydirX;
        else
            ray->perpwalldist = (ray->mapY - ray->posY + (1 - ray->stepY) / 2) / ray->raydirY;
        ray->lineheight = (params->screenheight / ray->perpwalldist);
        ray->drawstart = (-ray->lineheight / 2 + (params->screenheight / 2));
        if (ray->drawstart < 0)
            ray->drawstart = 0;
        ray->drawend = ray->lineheight / 2 + (int)params->screenheight / 2;
        if (ray->drawend >= params->screenheight)
            ray->drawend = params->screenheight - 1;
        if(params->map[ray->mapX][ray->mapY] == 1)
            color->r = 255;
        if(params->map[ray->mapX][ray->mapY] == 2)
            color->g = 255;
        if(params->map[ray->mapX][ray->mapY] == 3)
            color->b = 255;
        ray->side == 1 ? color->colors /=  2 : 0;
        verline(x, ray->drawstart, ray->drawend, params);
    }    
    return;    
}