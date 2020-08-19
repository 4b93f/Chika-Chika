/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becentrale <becentrale@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:30:34 by becentrale        #+#    #+#             */
/*   Updated: 2020/08/19 18:45:43 by becentrale       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray ft_create_ray()
{
    t_ray ray;
    int w = 0;
    int mapY = 0;
    int mapX = 0;
    int stepX = 0;
    int stepY = 0;
    int hit = 0;
    int side = 0;
    int lineheight = 0;
    int drawstart = 0;
    int drawend = 0;
    int movespeed = 0;
    int rotspeed = 0;
    double posX = 0;
    double posY = 0;
    double dirX = 0;
    double dirY = 0;
    double planeX = 0;
    double planeY = 0;
    double raydirX = 0;
    double raydirY = 0;
    double camX = 0;
    double sidedistX = 0; // distance entre ray et prochain axe Y//
    double sidedistY = 0; // distance entre ray et prochain axe X//
    double deltadistX = 0; // distance entre le 1er axe X et le 2eme //
    double deltadistY = 0;  // distance entre le 1er axe Y et le 2eme //
    double perpwalldist = 0;
    void *mlx;
    void *window;
    return(ray);
}

t_ray *ft_malloc_ray()
{
    t_ray *malloc_ray;
    malloc_ray = malloc(sizeof(t_ray));
    *malloc_ray = ft_create_ray();
    return(malloc_ray);
}
