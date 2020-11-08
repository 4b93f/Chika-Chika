/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:42:38 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/08 16:44:11 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

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
