/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:16:21 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/12 16:34:58 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_getpose_sprite(char **map, t_params *params)
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
				params->sprites[k].x = i + 1;
				params->sprites[k].y = j + 1;
				k++;
				map[i][j] = '0';
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	param_r(t_params *params, char *str)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	params->res_x = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	params->res_y = ft_atoi(str + i);
	while (ft_isspace(str[i]))
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		quit(ERROR_ARGUMENT, params);
	return ;
}

void		ft_resolution(t_params *params)
{
	char	**tmp;
	int		res_screen_x;
	int		res_screen_y;
	void	*mlx;

	mlx = mlx_init();
	tmp = NULL;
	if (!params->res)
		ft_error(params, ANOMALY_RES);
	param_r(params, params->res);
	mlx_get_screen_size(mlx, &res_screen_x, &res_screen_y);
	params->screenwidth = params->res_y > res_screen_y
	? res_screen_y : params->res_y;
	params->screenheight = params->res_x > res_screen_x
	? res_screen_x : params->res_x;
	if (params->screenwidth < 1 || params->screenheight < 1)
		quit(ANOMALY_RES, params);
}

int			ft_check_map(t_params *params, char **map)
{
	int i;
	int j;
	int k;

	i = 1;
	j = -1;
	k = 0;
	if (!map[2])
		ft_error(params, WRONG_MAP_FORMAT);
	if (ft_updownwall(map[0]) == 0)
		ft_error(params, WRONG_MAP_FORMAT);
	while (map[i + 1] != NULL)
	{
		if (ft_check_char(params, map[i]) == FALSE)
			ft_error(params, WRONG_MAP_FORMAT);
		i++;
	}
	if (ft_updownwall(map[i]) == 0)
		ft_error(params, WRONG_MAP_FORMAT);
	if (ft_check_space(j, k, params, map) == 0)
		ft_error(params, WRONG_MAP_FORMAT);
	if (params->find_pos != 1)
		ft_error(params, WRONG_MAP_FORMAT);
	return (TRUE);
}
