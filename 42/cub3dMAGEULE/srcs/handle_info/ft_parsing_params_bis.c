/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_params_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:45:46 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/03 18:13:39 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cut(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while (i != 0)
	{
		if (ft_isspace(s[i]))
		{
			while (ft_isspace(s[i]))
				i--;
			s[i + 1] = '\0';
			return ;
		}
		else if (ft_isascii(s[i]))
			return ;
		i--;
	}
}

void	ft_check_floor(t_params *params)
{
	int i;
	int j;

	i = -1;
	j = 0;
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

	i = -1;
	j = 0;
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