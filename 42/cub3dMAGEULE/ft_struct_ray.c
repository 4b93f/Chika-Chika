/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:30:34 by becentrale        #+#    #+#             */
/*   Updated: 2020/09/08 21:41:14 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray ft_create_ray(t_params *params)
{
    t_ray ray;
    ray.width = 0;
    ray.posX = 0;
    ray.posY = 0;
    ray.dirX = 1;
    ray.dirY = 0;
    ray.planeX = 0;
    ray.planeY = 0.66;
    ray.raydirX = 0;
    ray.raydirY = 0;
    ray.camX = 0;
    ray.deltadistX = 0; // distance entre le 1er axe X et le 2eme //
    ray.deltadistY = 0;  // distance entre le 1er axe Y et le 2eme //
    ray.hit = 0;
    ray.mapY = 0;
    ray.mapX = 0;
    ray.stepX = 0;
    ray.stepY = 0;
    ray.side = 0;
    ray.sidedistX = 0; // distance entre ray et prochain axe Y//
    ray.sidedistY = 0; // distance entre ray et prochain axe X//
    ray.perpwalldist = 0;
    ray.lineheight = 0;
    /***************************************/
    ray.drawstart = 0;
    ray.drawend = 0;
    ray.movespeed = 0;
    ray.rotspeed = 0;
    ray.mlx = mlx_init();
    ray.window = mlx_new_window(ray.mlx,params->screenwidth, params->screenheight, "TITLE");
    return(ray);
}

t_ray *ft_malloc_ray(t_params *params)
{
    t_ray *malloc_ray;
    malloc_ray = malloc(sizeof(t_ray));
    *malloc_ray = ft_create_ray(params);
    return(malloc_ray);
}
