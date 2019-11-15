/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:49:49 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/03 06:22:15 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_nan_mais_tu_le_fais_expres(int x, int y)
{
	int	a;

	a = 1;
	if (x <= 0 || y <= 0)
	{
		ft_putstr("Erreur, veuillez taper des nombres > 0");
		ft_putchar('\n');
		return (0);
	}
	return (1);
}

void	rush00(int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y & ft_nan_mais_tu_le_fais_expres(x, y) == 1)
	{
		j = 0;
		while (j < x)
		{
			if ((i == 0 && j == 0) || (i == (y - 1) && y != 1 && j == (x - 1) &&
						x != 1) || (i == (y - 1) && j == 0)
					|| (i == 0 && j == (x - 1)))
				ft_putchar('o');
			else if (((i == 0 && j == (x - 1)) || (i == 0 && j != 0
							&& j != x - 1) || (j != 0 && i == (y - 1))))
				ft_putchar('-');
			else if ((i != 0 && i != (y - 1)) && (j != 0 && j != (x - 1)))
				ft_putchar(' ');
			else
				ft_putchar('|');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
