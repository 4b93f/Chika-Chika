/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 01:14:46 by root              #+#    #+#             */
/*   Updated: 2020/11/07 17:14:48 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_params	ft_create_params(void)
{
	t_params	params;

	params.screenwidth = 0;
	params.screenheight = 0;
	params.map_find = 0;
	params.find_pos = 0;
	params.player_orientation = 0;
	params.res = NULL;
	params.textno = NULL;
	params.textso = NULL;
	params.textwe = NULL;
	params.textea = NULL;
	params.textsp = NULL;
	params.colorc = NULL;
	params.mlx_txt_n = NULL;
	params.mlx_txtdata_n = NULL;
	params.argbcolorc = NULL;
	params.colorf = NULL;
	params.argbcolorf = NULL;
	params.map = NULL;
	return (params);
}

t_params	*ft_malloc_params(void)
{
	t_params	*malloc_params;

	if (!(malloc_params = malloc(sizeof(t_params))))
		return (0);
	*malloc_params = ft_create_params();
	return (malloc_params);
}

void		ft_free_params(t_params *to_free)
{
	int			i;

	i = -1;
	while (to_free->map[++i])
		free(to_free->map[i]);
	free(to_free->map);
	free(to_free);
}