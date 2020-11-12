/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:30:34 by becentrale        #+#    #+#             */
/*   Updated: 2020/11/12 14:58:48 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_ray	ft_create_ray(t_params *params)
{
	t_ray ray;

	ray.width = 0;
	ray.raydirx = 0;
	ray.raydiry = 0;
	ray.deltadistx = 0;
	ray.deltadisty = 0;
	ray.hit = 0;
	ray.mapy = 0;
	ray.mapx = 0;
	ray.stepx = 0;
	ray.stepy = 0;
	ray.side = 0;
	ray.sidedistx = 0;
	ray.sidedisty = 0;
	ray.perpwalldist = 0;
	ray.lineheight = 0;
	ray.drawstart = 0;
	ray.drawend = 0;
	if (!(ray.mlx = mlx_init()))
		quit(MALLOC_ERROR, params);
	if (!(ray.window = mlx_new_window(ray.mlx, params->screenwidth,
	params->screenheight, "TITLE")))
		quit(MALLOC_ERROR, params);
	return (ray);
}

t_ray			*ft_malloc_ray(t_params *params)
{
	t_ray *malloc_ray;

	if (!(malloc_ray = malloc(sizeof(t_ray))))
		quit(MALLOC_ERROR, params);
	*malloc_ray = ft_create_ray(params);
	return (malloc_ray);
}
