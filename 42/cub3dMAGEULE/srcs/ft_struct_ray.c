/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:30:34 by becentrale        #+#    #+#             */
/*   Updated: 2020/10/18 23:29:32 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	ft_create_ray(t_params *params)
{
	t_ray ray;

	ray.width = 0;
	ray.raydirX = 0;
	ray.raydirY = 0;
	ray.deltadistX = 0;
	ray.deltadistY = 0;
	ray.hit = 0;
	ray.mapY = 0;
	ray.mapX = 0;
	ray.stepX = 0;
	ray.stepY = 0;
	ray.side = 0;
	ray.sidedistX = 0;
	ray.sidedistY = 0;
	ray.perpwalldist = 0;
	ray.lineheight = 0;
	ray.drawstart = 0;
	ray.drawend = 0;
	ray.mlx = mlx_init();
	ray.window = mlx_new_window(ray.mlx, params->screenwidth,
	params->screenheight, "TITLE");
	return (ray);
}

t_ray	*ft_malloc_ray(t_params *params)
{
	t_ray *malloc_ray;

	malloc_ray = malloc(sizeof(t_ray));
	*malloc_ray = ft_create_ray(params);
	return (malloc_ray);
}
