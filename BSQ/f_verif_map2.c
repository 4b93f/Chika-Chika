/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_verif_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:23:37 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/19 14:24:36 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_verif_is_only_obs(char **strs, char *cara)
{
	int i;
	int	j;

	i = 1;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == cara[0])
				return (FALSE);
			j++;
		}
		i++;
	}
	return(TRUE);
}

int		ft_verif_if_only_vide(char **strs, char *cara)
{
	int i;
	int	j;

	i = 1;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] != cara[1])
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
