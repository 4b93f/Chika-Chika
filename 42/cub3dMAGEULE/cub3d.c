/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:14:13 by chly-huc          #+#    #+#             */
/*   Updated: 2020/03/11 18:09:06 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 1024
#define screenHeight 1024

void ft_init_struct(t_struct *info)
{
    info->posX = 6;
    info->posY = 12;
    info->dirX = -1;
    info->dirY = 0;
    info->planeX = 0;
    info->planeY = 0.66;
    info->camX = 0;
    info->w = mapWidth;
    info->raydirX = 0;
    info->raydirX = 0;
    info->deltadistX = 0;
    info->deltadistY = 0;
    info->perpwalldist = 0;
    info->lineheight = 0;
    info->drawstart = 0;
    info->drawend = 0;
    info->movespeed = 0;
    info->rotspeed = 0;
}

void ft_init_color(t_color *color)
{
    color->r = 0;
    color->g = 0;
    color->b = 0;
    color->colors = 0;
}

void verline(int x, int drawstart, int drawend, t_struct info)
{
    while (drawstart < drawend)
    {
        mlx_pixel_put(info.mlx, info.window, x, drawstart, 65030);
        drawstart++;
    }
}

int ft_cub3d(t_struct *info, t_color color)
{
    int x;
    int fd;
    char **worldMap;

    x = -1;
    fd = open("map.txt", O_RDONLY);
    worldMap = ft_parsing(fd);
    while (++x < screenWidth)
    {
        info->camX = 2 * x / screenWidth - 1;
        info->raydirX = info->dirX + info->planeX * info->camX;
        info->raydirY = info->dirY + info->planeY * info->camX;
        /*****************************************************************************************************************************/
        info->deltadistX = (info->raydirX == 0) ? 0 : ((info->raydirY == 0) ? 1 : (info->raydirY * info->raydirY) / (1 / info->raydirY));
        info->deltadistY = (info->raydirX == 0) ? 0 : ((info->raydirY == 0) ? 1 : (info->raydirX * info->raydirX) / (1 / info->raydirX));
        int mapX;
        int mapY;
        double sidedistX;
        double sidedistY;
        double perpwalldist;
        int hit = 0;
        int side;

        mapX = (int)info->posX;
        mapY = (int)info->posY;
        /*****************************************************************************************************************************/
        if (info->raydirX < 0)
        {
            info->stepX = -1;
            sidedistX = (info->posX - mapX) * info->deltadistX;
        }
        else
        {
            info->stepX = 1;
            sidedistX = (mapX + 1.0 - info->posX) * info->deltadistX;
        }
        if (info->raydirY < 0)
        {
            info->stepY = - 1;
            sidedistY = (info->posY - mapY) * info->deltadistY;
        }
        else
        {
            info->stepY = 1;
            sidedistY = (mapY + 1.0 - info->posY) * info->deltadistY;
        }

        while (hit == 0)
        {
            if (sidedistX < sidedistY)
            {
                sidedistX += info->deltadistX;
                mapX += info->stepX;
                side = 0;
            }
            else
            {
                sidedistY += info->deltadistY;
                mapY += info->stepY;
                side = 1;
            }
            if (worldMap[mapX][mapY] > 0) 
                hit = 1;
        }
        if (side == 0)
            perpwalldist = (mapX - info->posX + (1 - info->stepX) / 2) / info->raydirX;
        else
            perpwalldist = (mapY - info->posY + (1 - info->stepY) / 2) / info->raydirY;
        int lineheight;
        lineheight = (int)(screenHeight / perpwalldist);
        info->drawstart = (-lineheight) / 2 + screenHeight / 2;
        if (info->drawstart < 0) 
            info->drawstart = 0;
        info->drawend = lineheight / 2 + screenHeight / 2;
        if (info->drawend >= screenHeight)
            info->drawend = screenHeight - 1;
        if (worldMap[mapX][mapY] == 1)
            color.r = 255;
        if (worldMap[mapX][mapY] == 2)
            color.g = 225;
        if (worldMap[mapX][mapY] == 3) 
            color.b = 255;
        side == 1 ? color.colors /=  2 : 0;
        //printf("drawStart == %d\n", info->drawstart);
        //printf("drawEnd == %d\n", info->drawend);
        //printf("hit == %d\n", hit);
        verline(x, info->drawstart, info->drawend, *info);
    }
    return (0);
}

unsigned int rgb_to_jeff(t_color color)
{
    return (color.r * 65536 + color.g * 256 + color.b);
}

int main()
{
    t_struct info;
    t_color color;
  
    ft_init_struct(&info);
    ft_init_color(&color);
    color.colors = rgb_to_jeff(color);
    info.mlx = mlx_init();
    info.window = mlx_new_window(info.mlx, screenWidth, screenHeight, "RAYCASTING");
    ft_cub3d(&info, color);
    mlx_loop(info.mlx);
    return (0);
}
