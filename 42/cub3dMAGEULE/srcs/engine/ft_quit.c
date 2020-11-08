/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:07:53 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/08 20:25:18 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_struct(t_params *params)
{
	ft_free_sprite(params->sp);
	ft_free_tex(params->tex);
	free(params->color);
	free(params->sv);
	free(params->sprites);
	free(params->image);
	free(params->bmp);
	free(params->player);
	ft_free_params(params);
}

void	quit(int num, t_params *params)
{
	static char *error[] = {
		"Error\nMap file not include\n",
		"Error\nWrong parameters in map file\n",
		"Error\nMap not found\n",
		"Error\nMalloc error\n",
		"Error\nx2 same parameters in map file\n",
		"Error\nAnomaly with textures\n",
		"Error\nRGB color need to be < 256 and >= 0\n",
		"Error\nMissing something in RGB Color\n",
		"Error\nWrong format in RGB color\n",
		"Error\nMissing/Wrong Resolution\n",
		"Error\nPlayer not found\n",
		"Error\nAnomaly with sprite\n",
		"Error\nMissing parameters\n",
		"Error\nWrong format in map\n",
		"Error\nInvalid argument\n"
	};

	if (num > -1)
		ft_printf("%s", error[num]);
	free_struct(params);
	exit(0);
}
