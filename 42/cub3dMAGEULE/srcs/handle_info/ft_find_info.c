/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:16:21 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/07 18:29:06 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	ft_resolution(t_params *params)
{
	char	**tmp;

	tmp = NULL;
	if (!params->res)
		ft_error(params, ANOMALY_RES);
	if (!(tmp = ft_split(params->res, ' ')))
		return ;
	if (tmp[2] || tmp[0] == NULL || tmp[1] == NULL)
		quit(ANOMALY_RES, params);
	params->screenwidth = ft_atoi(tmp[0]);
	params->screenheight = ft_atoi(tmp[1]);
	if (params->screenwidth < 1 || params->screenheight < 1)
		quit(ANOMALY_RES, params);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
}

int		ft_check_map(t_params *params, char **map)
{
	int i;
	int j;
	int k;

	i = 1;
	j = -1;
	k = 0;
	if (!map[2])
		return (FALSE);
	if (ft_updownwall(map[0]) == 0)
		return (FALSE);
	while (map[i + 1] != NULL)
	{
		if (ft_check_char(params, map[i]) == FALSE)
			return (FALSE);
		i++;
	}
	if (ft_updownwall(map[i]) == 0)
		return (FALSE);
	if (ft_check_space(j, k, params, map) == 0)
		return (FALSE);
	if (params->find_pos != 1)
		ft_error(params, WRONG_PARAMS);
	return (TRUE);
}
