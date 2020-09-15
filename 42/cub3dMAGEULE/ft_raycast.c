/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:50:31 by becentrale        #+#    #+#             */
/*   Updated: 2020/09/15 21:13:18 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void verline(int x, int drawstart, int drawend, t_ray *ray)
{
    while (drawstart < drawend)
    {
        mlx_pixel_put(ray->mlx, ray->window, x, drawstart, 65030);
        drawstart++;
    }
}


void    ft_mlx_pixel_to_image(int x, int drawstart, int drawend, t_params *params)
{
    unsigned char r = 255;
    unsigned char g = 0;

    params->image->img = mlx_new_image(params->ray->mlx, 1000, 1000);
    params->image->imgdata = mlx_get_data_addr(params->image->img, &params->image->bpp, &params->image->sizeline, &params->image->endian);
    while (drawstart < drawend)
    {
        params->image->imgdata[x * 4 + 4 * drawstart] = r;
        params->image->imgdata[x * 4 + 4 * drawstart + 1] = g;
        params->image->imgdata[x * 4 + 4 * drawstart + 2] = r;
        x++;
        
    }
    x = 0;
    printf("!\n");
    printf("%d\n", x);
}


void ft_raycast(t_params *params,t_ray *ray, t_color *color)
{
    int x;

    x = 0;
    while(x++ < params->screenwidth)
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
        ft_mlx_pixel_to_image(x, ray->drawstart, ray->drawend, params);
    }    
    return;    
}