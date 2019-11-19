/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_verif_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:33:55 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/19 20:05:35 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_verif_is_only_obs(char **map, char *code)
{
	int i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == code[0])
				return (TRUE);
			j++;
		}
		i++;
	}
	return(FALSE);
}

int		ft_verif_if_only_vide(char **map, char *code)
{
	int i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != code[1])
				return (TRUE);
			j++;
		}
		i++;
	}
	return(FALSE);
}

int		ft_verif_if_same(char *code)
{
	if(code[0] == code[1])
		return(FALSE);
	if(code[0] == code[2])
		return(FALSE);
	if(code[1] == code[2])
		return(FALSE);
	return(TRUE);
}

int ft_verif_is_toolong(char **map)
{
	int len;
	int i;
	int j;

	i = 0;
	j = 0;
	len = ft_atoi(map[0]);
	while (map[i])
		i++;
	if(i - 1 > len)
	{
		return (FALSE);
	}
	i = 0;
	while(map[0][i])
	{
		while (map[0][i] >= '0' && map[0][i] <= '9')
			i++;
		while (map[0][i])
			i++;
		if (i - 1 > len)
			return(FALSE);
		i++;
	}
	return(TRUE);
}

