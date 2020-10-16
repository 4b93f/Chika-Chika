/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:08:45 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/16 15:13:17 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void up(t_params *params)
{
    //printf("pos joueur = {%f} {%f}\n ", params->ray->posX, params->ray->posY);
    if(params->map[(int)(params->ray->posX + params->ray->dirX * params->ray->movespeed)][(int)params->ray->posY] == '0' && 
    params->map[(int)(params->ray->posX + params->ray->dirX * params->ray->movespeed)][(int)(params->ray->posY - 0.01)] == '0' && 
    params->map[(int)(params->ray->posX + params->ray->dirX * params->ray->movespeed)][(int)(params->ray->posY + 0.01)] == '0')
    {
        params->ray->posX += params->ray->dirX * 0.1;
    }
    if(params->map[(int)params->ray->posX][(int)(params->ray->posY + params->ray->dirY * params->ray->movespeed)] == '0' && 
    params->map[(int)(params->ray->posX - 0.01)][(int)(params->ray->posY + 0.01 + params->ray->dirY * params->ray->movespeed)] == '0' &&
    params->map[(int)(params->ray->posX + 0.01)][(int)(params->ray->posY - 0.01 + params->ray->dirY * params->ray->movespeed)] == '0')
    {
        params->ray->posY += params->ray->dirY * 0.1;
    }
    reset_image(params);
}

void down(t_params *params)
{   
    if(params->map[(int)(params->ray->posX - params->ray->dirX * params->ray->movespeed)][(int)params->ray->posY]== '0' && 
    params->map[(int)(params->ray->posX - params->ray->dirX * params->ray->movespeed)][(int)(params->ray->posY + 0.01)] == '0' &&
    params->map[(int)(params->ray->posX - params->ray->dirX * params->ray->movespeed)][(int)(params->ray->posY - 0.01)] == '0')
         params->ray->posX -= params->ray->dirX * 0.1;

    if(params->map[(int)params->ray->posX][(int)(params->ray->posY - params->ray->dirY * params->ray->movespeed)]== '0' &&
    params->map[(int)(params->ray->posX + 0.01)][(int)(params->ray->posY - params->ray->dirY * params->ray->movespeed)]== '0' &&
    params->map[(int)(params->ray->posX - 0.01)][(int)(params->ray->posY - params->ray->dirY * params->ray->movespeed)]== '0')
        params->ray->posY -= params->ray->dirY * 0.1;
    reset_image(params);
}
        
void left(t_params *params)
{
    if (params->map[(int)(params->ray->posX - params->ray->planeX * params->ray->movespeed)][(int)(params->ray->posY)] == '0' &&
    params->map[(int)(params->ray->posX - params->ray->planeX * params->ray->movespeed)][(int)(params->ray->posY - 0.01)] == '0' &&
    params->map[(int)(params->ray->posX - params->ray->planeX * params->ray->movespeed)][(int)(params->ray->posY + 0.01)] == '0')
        params->ray->posX -=  params->ray->planeX * 0.1;
    if (params->map[(int)params->ray->posX][(int)(params->ray->posY - params->ray->planeY * params->ray->movespeed)] == '0' &&
    params->map[(int)(params->ray->posX - 0.01)][(int)(params->ray->posY - params->ray->planeY * params->ray->movespeed)] == '0' &&
    params->map[(int)(params->ray->posX + 0.01)][(int)(params->ray->posY - params->ray->planeY * params->ray->movespeed)] == '0')
        params->ray->posY -=  params->ray->planeY * 0.1;
    reset_image(params);
}

void right(t_params *params)
{
    if (params->map[(int)(params->ray->posX + params->ray->planeX * params->ray->movespeed)][(int)(params->ray->posY)] == '0' && 
    params->map[(int)(params->ray->posX + params->ray->planeX * params->ray->movespeed)][(int)(params->ray->posY + 0.01)] == '0' &&
    params->map[(int)(params->ray->posX + params->ray->planeX * params->ray->movespeed)][(int)(params->ray->posY - 0.01)] == '0')
        params->ray->posX += params->ray->planeX * 0.1;
    if (params->map[(int)params->ray->posX][(int)(params->ray->posY + params->ray->planeY * params->ray->movespeed)] == '0' &&
    params->map[(int)(params->ray->posX + 0.01)][(int)(params->ray->posY + params->ray->planeY * params->ray->movespeed)] == '0' &&
    params->map[(int)(params->ray->posX - 0.01)][(int)(params->ray->posY + params->ray->planeY * params->ray->movespeed)] == '0')
         params->ray->posY += params->ray->planeY * 0.1;
    reset_image(params);
}

 