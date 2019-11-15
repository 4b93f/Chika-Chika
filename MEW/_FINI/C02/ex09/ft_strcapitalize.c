/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:28:59 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/04 23:44:04 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_cheat(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int prem;

	i = 0;
	prem = 0;
	ft_cheat(str);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && prem == 0)
		{
			str[i] = str[i] - 32;
			prem = 1;
		}
		if (str[i] >= '0' && str[i] <= '9')
			prem = 1;

		else if (!((str[i] > 96 && str[i] <= 122)
		|| (str[i] >= 65 && str[i] <= 90)))
			prem = 0;
		i++;
	}
	return (str);
}