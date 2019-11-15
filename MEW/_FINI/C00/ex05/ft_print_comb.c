/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:16:41 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/09 01:21:39 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_arret(char a, char b, char c, char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	ft_putchar(d);

	if (!(a == '4' && b == 3 && c == 2 && d == 1))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;
	int d;

	a = 1;
	b = 2; 
	c = 3;
	d = 4;
	while (a < 4)
	{
		if(b == a)
			b = 1;
		while (b < 4)
		{
			if(b == d)
				c = 1;
			while (c < 4)
			{
				if(d == c)
					d = 1;
				while(d < 4)
				{
					ft_arret(a + '0', b + '0', c + '0', d + '0');
					d++;
				}
				d = 1;
				c++;
			}
			c = 1;
			b++;
		}
		b = 1;
		a++;
	}
}

int main()
{
	ft_print_comb();
}
