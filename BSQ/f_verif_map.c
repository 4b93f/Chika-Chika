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
	int		len;
	int 	j;
	int 	y;
	
	len = ft_atoi(str[0]);
	i = 0;
	while(str[++i])
		if (ft_strlen[i] != len)
			return (FALSE);
	return(TRUE);
}