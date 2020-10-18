/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:36:46 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/18 23:12:51 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_getposray(char **map, t_player *player)
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
                player->posX = i + 0.5;
                player->posY = j + 0.5;
                map[i][j] = '0';
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void turn_left(t_params *params)
{
    double olddirx;
    double oldplanex;
        
    olddirx = params->player->dirX;
    oldplanex = params->player->planeX;

    params->player->dirX =  params->player->dirX * cos(-params->player->rotspeed) - params->player->dirY * sin (-params->player->rotspeed);
    params->player->dirY = olddirx * sin(-params->player->rotspeed) + params->player->dirY * cos(-params->player->rotspeed);
    params->player->planeX = params->player->planeX * cos(-params->player->rotspeed) - params->player->planeY * sin(-params->player->rotspeed);
    params->player->planeY = oldplanex * sin(-params->player->rotspeed) + params->player->planeY * cos(-params->player->rotspeed);
    reset_image(params);
}

void turn_right(t_params *params)
{
    double olddirx;
    double oldplanex;
    olddirx = params->player->dirX;
    oldplanex = params->player->planeX;

    params->player->dirX =  params->player->dirX * cos(params->player->rotspeed) - params->player->dirY * sin (params->player->rotspeed);
    params->player->dirY = olddirx * sin(params->player->rotspeed) + params->player->dirY * cos(params->player->rotspeed);
    params->player->planeX = params->player->planeX * cos(params->player->rotspeed) - params->player->planeY * sin(params->player->rotspeed);
    params->player->planeY = oldplanex * sin(params->player->rotspeed) + params->player->planeY * cos(params->player->rotspeed);
    reset_image(params);
}


int intcmp(int x, int y)
{
    int total = y - x;
    if (total == 0)
        return (TRUE);
    else
        return (FALSE);
}

void ft_orientation(t_params *params, t_ray *ray)
{
    if (intcmp(params->player_orientation, 'N') == 1)
    {
        params->player->dirX = -1.0;
        params->player->planeY = 0.66;
    }
    if (intcmp(params->player_orientation,'S') == 1)
    {
       	params->player->dirX = 1.0;
        params->player->planeY = -0.66;
    }
    if (intcmp(params->player_orientation, 'W') == 1)
    {
        params->player->dirY = -1.0;
        params->player->planeX = -0.66;
    }
    if (intcmp(params->player_orientation, 'E') == 1)
    {
        params->player->dirY = 1.0;
        params->player->planeX = 0.66;
    }
}