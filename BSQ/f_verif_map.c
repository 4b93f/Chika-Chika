/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_verif_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:56:34 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/19 15:16:08 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_verif_map(char **map)
{
	int		i;
	int		len;
	int 	j;
	int 	y;
	
	len = ft_atoi(map[0]);
	i = 0;
	while(map[++i])
		if (ft_strlen(map[i]) != len)
			return (FALSE);
	return(TRUE);
}

char	*ft_recup_code(char **map)
{
	int		i;
	char	*code;
	int		lenstr;
	if (!(code = (char *)malloc(sizeof(char) * 4)))
		return (NULL);
	lenstr = ft_strlen(map[0]);
	if (lenstr > 4)
	{
		code[3] = '\0';
		code[2] = map[0][lenstr - 1];
		code[1] = map[0][lenstr - 2];
		code[0] = map[0][lenstr - 3];
	}
	else
		return (NULL);
	return (code);
}

int		ft_verif_cara(char **map, char *code)
{
	int i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != code[0] && map[i][j] != code[1]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return(TRUE);
}
