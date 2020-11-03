/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:30:33 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/03 21:31:05 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_new_tex(t_params *params, char *path)
{
	if (!(params->tex->texture = mlx_xpm_file_to_image(params->ray->mlx, path,
	&params->tex->tex_width, &params->tex->tex_height)))
		ft_error(ANOMALY_TEXTURES);
	params->tex->texturedata = mlx_get_data_addr(params->tex->texture,
	&params->tex->bpp,
	&params->tex->sizeline, &params->tex->endian);
	return (params->tex->texturedata);
}

void	ft_get_tex(t_params *params)
{
	params->tex->tex[0] = ft_new_tex(params, params->textno);
	params->tex->tex[1] = ft_new_tex(params, params->textso);
	params->tex->tex[2] = ft_new_tex(params, params->textwe);
	params->tex->tex[3] = ft_new_tex(params, params->textea);
}
