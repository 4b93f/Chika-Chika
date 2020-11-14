/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:12:57 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/14 18:48:27 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	reset_image(t_params *params)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < (params->screenwidth * params->screenheight))
	{
		params->image->imgdata[x * 4 + y *
		params->image->sizeline] = (int)0;
		params->image->imgdata[x * 4 + y *
		params->image->sizeline + 1] = (int)0;
		params->image->imgdata[x * 4 + y *
		params->image->sizeline + 2] = (int)0;
		x++;
	}
}

void	ft_sprite_to_image(t_params *params)
{
	int isblack;

	isblack = params->sp->spdata[params->sv->spx * 4 + params->sv->spy *
		params->sp->sizeline + 1] + params->sp->spdata[params->sv->spx * 4 +
		params->sv->spy * params->sp->sizeline + 2] + params->sp->spdata
		[params->sv->spx * 4 + params->sv->spy * params->sp->sizeline + 3];
	if (isblack)
	{
		params->image->imgdata[params->sv->x * 4 + params->sv->y *
		params->image->sizeline + 0] = params->sp->spdata[params->sv->spx * 4
			+ params->sv->spy * params->sp->sizeline + 0];
		params->image->imgdata[params->sv->x * 4 + params->sv->y *
			params->image->sizeline +
			1] = params->sp->spdata[params->sv->spx * 4 + params->sv->spy *
			params->sp->sizeline + 1];
		params->image->imgdata[params->sv->x * 4 + params->sv->y *
			params->image->sizeline +
			2] = params->sp->spdata[params->sv->spx * 4 + params->sv->spy *
			params->sp->sizeline + 2];
		params->image->imgdata[params->sv->x * 4 + params->sv->y *
			params->image->sizeline +
			3] = params->sp->spdata[params->sv->spx * 4 + params->sv->spy *
			params->sp->sizeline + 3];
	}
}

void	ft_pixel_to_image(int x, int y, t_params *params)
{
	params->image->imgdata[x * 4 + y * params->image->sizeline
		+ 0] = params->color->b;
	params->image->imgdata[x * 4 + y * params->image->sizeline
		+ 1] = params->color->g;
	params->image->imgdata[x * 4 + y * params->image->sizeline
		+ 2] = params->color->r;
	params->image->imgdata[x * 4 + y * params->image->sizeline
		+ 3] = params->color->a;
}
