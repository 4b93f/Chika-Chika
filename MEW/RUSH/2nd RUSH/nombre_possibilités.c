/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nombre_possibilités.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 06:38:24 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/10 12:00:22 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	rush(void)
{
	int a;
	int b;
	int c;
	int d;
	int count;
	
	a = 1;
	b = 1;
	c = 1;
	d = 1;
	count = 0;
	
	while(a <= 4)
	{
		while (b <= 4)
		{
			while(c <= 4)
			{
				while(d <= 4)
				{
					if (a != b && a != c && a != d && b != c && b != d && c != d) 	
						{
						printf("%d%d%d%d\n", a, b, c, d);
						count++;
						}	
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
	printf("%d\n", count);
}

int main()
{
	rush();
}