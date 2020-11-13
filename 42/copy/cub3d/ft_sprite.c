/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:49:20 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/13 18:12:18 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_new_sprite(t_params *params, char *path)
{
	if (!(params->sp->mlx_sprite = mlx_xpm_file_to_image(params->ray->mlx, path,
	&params->sp->sp_width, &params->sp->sp_height)))
		quit("ANOMALY_SPRITE");
	params->sp->spdata = mlx_get_data_addr(params->sp->mlx_sprite,
	&params->sp->bpp,
	&params->sp->sizeline, &params->sp->endian);
	return (params->sp->spdata);
}

void		ft_get_sprite(t_params *params, char *path)
{
	params->sp->sp[0] = ft_new_sprite(params, path);
}
