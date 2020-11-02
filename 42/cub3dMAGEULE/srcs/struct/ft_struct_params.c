/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 01:14:46 by root              #+#    #+#             */
/*   Updated: 2020/11/02 20:33:51 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	params.textp = NULL;
	params.textf = NULL;
	params.colorc = NULL;
	params.argbcolorc = NULL;
	params.colorf = NULL;
	params.argbcolorf = NULL;
	params.map = NULL;
	params.mlx = mlx_init();
	return (params);
}

t_params	*ft_malloc_params(void)
{
	t_params	*malloc_params;

	malloc_params = malloc(sizeof(t_params));
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
