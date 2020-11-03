/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:04:20 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/03 21:32:00 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_next_value_bis(t_params *params, int x, double wallx, int *y)
{
	params->tex->texx = (int)(wallx * (double)TXTW);
	if (params->ray->side == 0 && params->ray->raydirx > 0)
		params->tex->texx = TXTW - params->tex->texx - 1;
	if (params->ray->side == 1 && params->ray->raydiry < 0)
		params->tex->texx = TXTW - params->tex->texx - 1;
	*y = params->ray->drawstart - 1;
	params->tex->step = 1.0 * TXTH / params->ray->lineheight;
	params->tex->texpos = (params->ray->drawstart - params->screenheight / 2
			+ params->ray->lineheight / 2) * params->tex->step;
	params->color->cell_index = params->ray->drawend;
	params->color->floor_index = 0;
}

void	print_cell_floor(t_params *params, t_color *color, int x)
{
	while (color->floor_index < params->ray->drawstart)
	{
		params->color->b = params->color->floor_b;
		params->color->g = params->color->floor_g;
		params->color->r = params->color->floor_r;
		ft_pixel_to_image(x, color->floor_index, params);
		color->floor_index++;
	}
	while (color->cell_index < params->screenheight)
	{
		params->color->b = params->color->cell_b;
		params->color->g = params->color->cell_g;
		params->color->r = params->color->cell_r;
		ft_pixel_to_image(x, color->cell_index, params);
		color->cell_index++;
	}
}

void	print_wall(t_params *params, int x, int y)
{
	while (++y < params->ray->drawend)
	{
		params->color->b = params->tex->tex[params->tex->texnum]
		[params->tex->texx * 4 + params->tex->texy * params->tex->sizeline + 0];
		params->color->g = params->tex->tex[params->tex->texnum]
		[params->tex->texx * 4 + params->tex->texy * params->tex->sizeline + 1];
		params->color->r = params->tex->tex[params->tex->texnum]
		[params->tex->texx * 4 + params->tex->texy * params->tex->sizeline + 2];
		params->color->a = params->tex->tex[params->tex->texnum]
		[params->tex->texx * 4 + params->tex->texy * params->tex->sizeline + 3];
		ft_pixel_to_image(x, y, params);
		params->tex->texy = (int)params->tex->texpos;
		params->tex->texpos += params->tex->step;
	}
}
