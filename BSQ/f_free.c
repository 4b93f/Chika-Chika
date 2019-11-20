/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:37:40 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/19 21:56:59 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_free_malloc(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
}
