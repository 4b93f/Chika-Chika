/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:30:33 by chly-huc          #+#    #+#             */
/*   Updated: 2020/10/30 17:39:54 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_new_tex(t_params *params, char *path)
{
	void	*tex;
	char	*texdata;

	if (!(tex = mlx_xpm_file_to_image(params->ray->mlx, path,
	&params->tex->tex_width, &params->tex->tex_height)))
		ft_error(ANOMALY_TEXTURES);
	texdata = mlx_get_data_addr(tex, &params->tex->bpp,
	&params->tex->sizeline, &params->tex->endian);
	return (texdata);
}

void	ft_get_tex(t_params *params)
{
	params->tex->tex[0] = ft_new_tex(params, params->textno);
	params->tex->tex[1] = ft_new_tex(params, params->textso);
	params->tex->tex[2] = ft_new_tex(params, params->textwe);
	params->tex->tex[3] = ft_new_tex(params, params->textea);
	return ;
}
