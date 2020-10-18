/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:36:46 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/18 16:38:36 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
                ray->posX = i + 0.5;
                ray->posY = j + 0.5;
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
        
    olddirx = params->ray->dirX;
    oldplanex = params->ray->planeX;

    params->ray->dirX =  params->ray->dirX * cos(-params->ray->rotspeed) - params->ray->dirY * sin (-params->ray->rotspeed);
    params->ray->dirY = olddirx * sin(-params->ray->rotspeed) + params->ray->dirY * cos(-params->ray->rotspeed);
    params->ray->planeX = params->ray->planeX * cos(-params->ray->rotspeed) - params->ray->planeY * sin(-params->ray->rotspeed);
    params->ray->planeY = oldplanex * sin(-params->ray->rotspeed) + params->ray->planeY * cos(-params->ray->rotspeed);
    reset_image(params);
}

void turn_right(t_params *params)
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
        ray->dirX = -1.0;
        ray->planeY = 0.66;
    }
    if (intcmp(params->player_orientation,'S') == 1)
    {
        ray->dirX = 1.0;
        ray->planeY = -0.66;
    }
    if (intcmp(params->player_orientation, 'W') == 1)
    {
        ray->dirY = -1.0;
        ray->planeX = -0.66;
    }
    if (intcmp(params->player_orientation, 'E') == 1)
    {
        ray->dirY = 1.0;
        ray->planeX = 0.66;
    }
}