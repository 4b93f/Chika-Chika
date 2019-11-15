/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:40:29 by chly-huc          #+#    #+#             */
/*   Updated: 2019/10/29 15:00:11 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_arret(int x, int y)
{
	char a;
	char b;
	char c;
	char d;

	a = '0' + x / 10;
	b = '0' + x % 10;
	c = '0' + y / 10;
	d = '0' + y % 10;
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
	if (x != 98 || y != 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int x;
	int y;

	x = 0;
	y = 1;
	while (x <= 98)
	{
		while (y <= 99)
		{
			ft_arret(x, y);
			y++;
		}
		x++;
		y = x + 1;
	}
}

int main()
{
	ft_print_comb2();
}
