/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_params_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:45:46 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/02 20:59:01 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		find_duplicate(char *str, int c)
{
	int i;
	int num;

	i = -1;
	num = 0;
	while (str[++i])
	{
		if (str[i] == c)
			num++;
	}
	return (num);
}

void	ft_check_floor(t_params *params)
{
	int i;
	int j;
	int k;
	int l;

	i = -1;
	j = 0;
	k = 0;
	l = 0;
	while (params->argbcolorf[++i])
	{
		while (params->argbcolorf[i][j] &&
				!ft_isdigit(params->argbcolorf[i][j]))
			j++;
		while (ft_isdigit(params->argbcolorf[i][j]))
			j++;
		while (params->argbcolorf[i][j])
		{
			if (!ft_isspace(params->argbcolorf[i][j]) &&
					ft_isascii(params->argbcolorf[i][j]))
				ft_error(WRONG_CHAR_IN_RGB);
			j++;
		}
		j = 0;
	}
}

void	ft_check_cell(t_params *params)
{
	int i;
	int j;
	int k;
	int l;

	i = -1;
	j = 0;
	k = 0;
	l = 0;
	while (params->argbcolorc[++i])
	{
		while (params->argbcolorc[i][j] &&
				!ft_isdigit(params->argbcolorc[i][j]))
			j++;
		while (ft_isdigit(params->argbcolorc[i][j]))
			j++;
		while (params->argbcolorc[i][j])
		{
			if (!ft_isspace(params->argbcolorc[i][j]) &&
					ft_isascii(params->argbcolorc[i][j]))
				ft_error(WRONG_CHAR_IN_RGB);
			j++;
		}
		j = 0;
	}
}

void	format_color(t_params *params)
{
	if (params->color->cell_r > 255 && params->color->cell_g > 255 &&
			params->color->cell_b > 255 && params->color->cell_r < 0 &&
			params->color->cell_g < 0 && params->color->cell_b < 0)
		ft_error(RGB_ERROR);
	if (params->color->floor_r > 255 && params->color->floor_g > 255 &&
			params->color->floor_g > 255 && params->color->floor_r < 0 &&
			params->color->floor_g < 0 && params->color->floor_b < 0)
		ft_error(RGB_ERROR);
}