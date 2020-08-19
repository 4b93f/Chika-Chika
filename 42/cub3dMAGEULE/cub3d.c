/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:14:13 by chly-huc          #+#    #+#             */
/*   Updated: 2020/08/09 01:19:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 1024
#define screenHeight 1024

/*
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
        //printf("drawStart == [%d]\n", info->drawstart);
        //printf("drawEnd == [%d]\n", info->drawend);
        //printf("hit == [%d]\n", hit);
        verline(x, info->drawstart, info->drawend, *info);
    }
    return (0);
}

unsigned int rgb_to_jeff(t_color color)
{
    return (color.r * 65536 + color.g * 256 + color.b);
}
*/
void ft_error()
{
    printf("error\n");
    exit(0);
}


int main(int argc, char **argv)
{
    if (argc != 2)
        exit(0);
    int fd;
    fd = open(argv[1], O_RDONLY);
    t_params *params;
    params = ft_malloc_struct(argv[1]);

    if (search_params(params, argv[1], fd) == 0)
        ft_error();
    if (params->map_find == 0)
        ft_error();
    //int i = 0;
    //while(params->map[i])
    //{
       //printf("%s\n", params->map[i]);
        //i++;
    //}
    //printf("\nSPRITE = [%s]\n", params->textsp);
    //printf("RES = [%s]\n", params->res);
    //printf("NO = [%s]\n", params->textno);
    //printf("SO = [%s]\n", params->textso);
    //printf("WE = [%s]\n", params->textwe);
    //printf("EA = [%s]\n", params->textea);
    //printf("F = [%s]\n", params->colorf);
    //printf("C = [%s]\n", params->colorc);
    if (ft_check_map(params->map) == 0)
        ft_error();
    //ft_free_struct(params);
}
