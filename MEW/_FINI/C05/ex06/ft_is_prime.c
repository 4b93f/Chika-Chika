/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:59:59 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/08 14:58:55 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	long	int nbr;
	int			i;

	nbr = nb;
	i = 2;
	if (nbr <= 0 || nbr == 1)
		return (0);
	while (nbr / i >= i)
		if (nbr % i++ == 0)
			return (0);
	return (1);
}

int main()
{
	printf("%d\n", ft_is_prime(10));
}
