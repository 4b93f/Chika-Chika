/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_verif_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:33:55 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/19 14:33:56 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_verif_is_only_obs(char **map, char *cara)
{
	int i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == cara[0])
				return (FALSE);
			j++;
		}
		i++;
	}
	return(TRUE);
}

int		ft_verif_if_only_vide(char **map, char *cara)
{
	int i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != cara[1])
				return (FALSE);
			j++;
		}
		i++;
	}
	return(TRUE);
}

int		ft_verif_if_same(char *cara)
{
	if(cara[0] == cara[1])
		return(FALSE);
	if(cara[0] == cara[2])
		return(FALSE);
	if(cara[1] == cara[2])
		return(FALSE);
	return(TRUE);
}
