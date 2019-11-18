/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_verif_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:56:34 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/18 20:50:08 by chly-huc         ###   ########.fr       */
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
		if (ft_strlen(str[i]) != len)
			return (FALSE);
	return(TRUE);
}

char	*ft_recup_code(char *str)
{
	int		i;
	char	*code;
	int		lenstr;

	if (!(code = (char *)malloc(sizeof(char) * 4)))
		return (NULL);
	lenstr = ft_strlen(str);
	if (lenstr > 4)
	{
		code[3] = '\0';
		code[2] = str[lenstr - 1];
		code[1] = str[lenstr - 2];
		code[0] = str[lenstr - 3];
	}
	else
	{
		return (NULL);
	}
	return (code);
}

int		ft_verif_cara(char **strs, char *cara)
{
	int i;
	int	j;

	i = 1;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (!(strs[i][j] == cara[0] || strs[i][j] == cara[1]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return(TRUE);
}
