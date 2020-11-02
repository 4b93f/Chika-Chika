/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:16:21 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/02 20:40:40 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_resolution(t_params *params)
{
	char	**tmp;
	int		res_x;
	int		res_y;

	if (!params->res)
		ft_error(ANOMALY_RES);
	if (!(tmp = ft_split(params->res, ' ')))
		return ;
	if (tmp[2] || tmp[0] == NULL || tmp[1] == NULL)
		ft_error(ANOMALY_RES);
	mlx_get_screen_size(params->ray->mlx, &res_x, &res_y);
	params->screenwidth = ft_atoi(tmp[0]);
	params->screenheight = ft_atoi(tmp[1]);
	if (params->screenwidth < 1 || params->screenheight < 1)
		ft_error(ANOMALY_RES);
	params->screenwidth = params->screenwidth >
		res_x ? res_x : params->screenwidth;
	params->screenheight = params->screenheight >
		res_y ? res_y : params->screenheight;
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
}

int		ft_check_map(t_params *params, char **map)
{
	int i;

	i = 1;
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
	if (ft_check_space(map) == 0)
		return (FALSE);
	if (params->find_pos != 1)
		ft_error(WRONG_PARAMS);
	return (TRUE);
}
