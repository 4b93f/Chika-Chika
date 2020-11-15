/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:30:33 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/15 18:59:04 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	west_east(t_params *params)
{
	if (!(params->mlx_txt_w = mlx_xpm_file_to_image(params->ray->mlx,
	params->textwe,
	&params->tex->tex_width, &params->tex->tex_height)))
		ft_error(ANOMALY_TEXTURES, params);
	params->mlx_txtdata_w = mlx_get_data_addr(params->mlx_txt_w,
	&params->tex->bpp, &params->tex->sizeline, &params->tex->endian);
	params->tex->tex[2] = params->mlx_txtdata_w;
	if (!(params->mlx_txt_e = mlx_xpm_file_to_image(params->ray->mlx,
	params->textea,
	&params->tex->tex_width, &params->tex->tex_height)))
		ft_error(ANOMALY_TEXTURES, params);
	params->mlx_txtdata_e = mlx_get_data_addr(params->mlx_txt_e,
	&params->tex->bpp,
	&params->tex->sizeline, &params->tex->endian);
	params->tex->tex[3] = params->mlx_txtdata_e;
}

static void	north_south(t_params *params)
{
	if (!(params->mlx_txt_n = mlx_xpm_file_to_image(params->ray->mlx,
	params->textno,
	&params->tex->tex_width, &params->tex->tex_height)))
		ft_error(ANOMALY_TEXTURES, params);
	params->mlx_txtdata_n = mlx_get_data_addr(params->mlx_txt_n,
	&params->tex->bpp, &params->tex->sizeline,
	&params->tex->endian);
	params->tex->tex[0] = params->mlx_txtdata_n;
	if (!(params->mlx_txt_s = mlx_xpm_file_to_image(params->ray->mlx,
	params->textso,
	&params->tex->tex_width, &params->tex->tex_height)))
		ft_error(ANOMALY_TEXTURES, params);
	params->mlx_txtdata_s = mlx_get_data_addr(params->mlx_txt_s,
	&params->tex->bpp, &params->tex->sizeline, &params->tex->endian);
	params->tex->tex[1] = params->mlx_txtdata_s;
}

void		ft_get_tex(t_params *params)
{
	north_south(params);
	west_east(params);
}
