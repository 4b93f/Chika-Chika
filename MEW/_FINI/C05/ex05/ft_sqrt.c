/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:28:36 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/05 20:39:16 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long int res;
	long int i;

	res = 0;
	i = 0;
	if (nb == 0 || nb < 0)
		return (0);
	while (nb > res)
	{
		res = i * i;
		if (res == nb)
			return (i);
		if (res > nb)
			return (0);
		i++;
	}
	return (0);
}
