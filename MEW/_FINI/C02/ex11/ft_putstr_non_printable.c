/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:25:15 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/03 21:24:59 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		t[3];

	t[0] = 0;
	while (str[t[0]])
	{
		if (str[t[0]] < 32 || str[t[0]] > 126)
		{
			ft_putchar('\\');
			t[2] = (str[t[0]] >= 0) ? str[t[0]] / 16 : (str[t[0]] + 256) / 16;
			t[1] = (str[t[0]] >= 0) ? str[t[0]] % 16 : (str[t[0]] + 256) % 16;
			if (t[1] > 9)
				t[1] = t[1] + 87;
			else
				t[1] = t[1] + 48;
			if (t[2] > 9)
				t[2] = t[2] + 87;
			else
				t[2] = t[2] + 48;
			ft_putchar(t[2]);
			ft_putchar(t[1]);
		}
		else
			ft_putchar(str[t[0]]);
		t[0]++;
	}
}
