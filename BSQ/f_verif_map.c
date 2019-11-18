/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_verif_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:56:34 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/18 19:38:25 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_verif_map(char **str)
{
	int		i;
	int 	j;
	int 	y;
	
	i = 0;
	y = ft_strlen(str[i + 1]);
	while(str[i + 1])
	{
		j = ft_strlen(str[i + 1]);
		if (y - j != 0)
			return(FALSE);
		i++;
	}
	return(TRUE);
}