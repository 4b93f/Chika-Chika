/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:49:20 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/02 20:38:33 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_getpose_sprite(char **map, t_draw_sprite *sp, t_sprite *sprites)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '2')
			{
				sprites[k].x = i + 1;
				sprites[k].y = j + 1;
				k++;
				map[i][j] = '0';
			}
			j++;
		}
		j = 0;
		i++;
	}
}

char	*ft_new_sprite(t_params *params, char *path)
{
	params->sp->test = mlx_new_image(params->mlx,
	params->sp->sp_width, params->sp->sp_height);
	params->sp->testdata = mlx_get_data_addr(params->sp->test, &params->sp->bpp,
	&params->sp->sizeline, &params->sp->endian);
	if (!(params->sp->lol = mlx_xpm_file_to_image(params->mlx, path,
	&params->sp->sp_width, &params->sp->sp_height)))
		ft_error(ANOMALY_SPRITE);
	params->sp->spdata = mlx_get_data_addr(params->sp->lol, &params->sp->bpp,
	&params->sp->sizeline, &params->sp->endian);
	return (params->sp->spdata);
}

void	ft_get_sprite(t_params *params, char *path)
{
	params->sp->sp[0] = ft_new_sprite(params, path);
}
