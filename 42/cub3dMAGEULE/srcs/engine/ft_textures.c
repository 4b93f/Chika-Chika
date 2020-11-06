/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:30:33 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/06 17:01:21 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_get_tex(t_params *params)
{
	void *tn;
	void *ts;
	void *tw;
	void *te;
	
	char *ok;
	char *ok1;

	if (!(tn = mlx_xpm_file_to_image(params->ray->mlx, params->textno,
	&params->tex->tex_width, &params->tex->tex_height)))
		ft_error(ANOMALY_TEXTURES);
	params->ptr->mlx_txtdata = mlx_get_data_addr(tn,
	&params->tex->bpp, &params->tex->sizeline,
	&params->tex->endian);
	params->tex->tex[0] = params->ptr->mlx_txtdata;
	
	if (!(ts = mlx_xpm_file_to_image(params->ray->mlx, params->textso,
	&params->tex->tex_width, &params->tex->tex_height)))
		ft_error(ANOMALY_TEXTURES);
	params->ptr->mlx_txtdata = mlx_get_data_addr(ts,
	&params->tex->bpp, &params->tex->sizeline, &params->tex->endian);

	params->tex->tex[1] = params->ptr->mlx_txtdata;
	
	if (!(tw = mlx_xpm_file_to_image(params->ray->mlx, params->textwe,
	&params->tex->tex_width, &params->tex->tex_height)))
		ft_error(ANOMALY_TEXTURES);
	params->ptr->mlx_txtdata = mlx_get_data_addr(tw,
	&params->tex->bpp, &params->tex->sizeline, &params->tex->endian);
	params->tex->tex[2] = params->ptr->mlx_txtdata;
	
	if (!(te = mlx_xpm_file_to_image(params->ray->mlx, params->textea,
	&params->tex->tex_width, &params->tex->tex_height)))
		ft_error(ANOMALY_TEXTURES);
	params->ptr->mlx_txtdata = mlx_get_data_addr(te,
	&params->tex->bpp,
	&params->tex->sizeline, &params->tex->endian);
	params->tex->tex[3] = params->ptr->mlx_txtdata;
}
