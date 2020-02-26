/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test-printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 16:54:40 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/07 17:19:51 by aalleman    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <wchar.h>
#include <locale.h>

int		ft_printf(const char *s, ...);

int		main(int ac, char **av)
{
	int		nb;
	int		count;

	nb = atoi(av[1]);
	count = 0;


	// [I - Tests with *].
	if (nb == count++)
		return(ac == 2 ? printf("%*d", 0, 42) : ft_printf("%*d", 0, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%*d", 0, 0) : ft_printf("%*d", 0, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*d", 10, 42) : ft_printf("%*d", 10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%*d", -10, 42) : ft_printf("%*d", -10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%0*d", -10, 42) : ft_printf("%0*d", -10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%0*d", 10, 42) : ft_printf("%0*d", 10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%0*d", 10, -42) : ft_printf("%0*d", 10, -42));
	if (nb == count++)
		return(ac == 2 ? printf("%0*d", 0, 42) : ft_printf("%0*d", 0, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%0*d", 10, 0) : ft_printf("%0*d", 10, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%0*d", -10, 0) : ft_printf("%0*d", -10, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*d", 010, 42) : ft_printf("%*d", 010, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%*s", 10, "Hello") : ft_printf("%*s", 10, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*s", -10, "Hello") : ft_printf("%*s", -10, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-*d", 10, 42) : ft_printf("%-*d", 10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%-*d", -10, 42) : ft_printf("%-*d", -10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%-*d", -10, -42) : ft_printf("%-*d", -10, -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", 0, 42) : ft_printf("%.*d", 0, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", 10, 42) : ft_printf("%.*d", 10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", -10, 42) : ft_printf("%.*d", -10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", 0, 0) : ft_printf("%.*d", 0, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", 10, 0) : ft_printf("%.*d", 10, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", -10, 0) : ft_printf("%.*d", -10, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", -0, 0) : ft_printf("%.*d", -0, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", -0, 42) : ft_printf("%.*d", -0, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", -0, -42) : ft_printf("%.*d", -0, -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.*s", -3, "Hello") : ft_printf("%.*s", -3, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%10.*d", 10, 42) : ft_printf("%10.*d", 10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%*.10d", 10, 42) : ft_printf("%*.10d", 10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 0, 0, 0) : ft_printf("%*.*d", 0, 0, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 0, 0, 42) : ft_printf("%*.*d", 0, 0, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 0, 0, -42) : ft_printf("%*.*d", 0, 0, -42));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 0, 5, 0) : ft_printf("%*.*d", 0, 5, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 0, -5, 0) : ft_printf("%*.*d", 0, -5, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 5, 0, 0) : ft_printf("%*.*d", 5, 0, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", -5, 0, 0) : ft_printf("%*.*d", -5, 0, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 5, 5, 0) : ft_printf("%*.*d", 5, 5, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 0, 0, "Hello") : ft_printf("%*.*s", 0, 0, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 0, 0, "Hello") : ft_printf("%*.*s", 0, 0, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 0, 0, "Hello") : ft_printf("%*.*s", 0, 0, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 0, 5, "Hello") : ft_printf("%*.*s", 0, 5, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 0, -5, "Hello") : ft_printf("%*.*s", 0, -5, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 5, 0, "Hello") : ft_printf("%*.*s", 5, 0, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", -5, 0, "Hello") : ft_printf("%*.*s", -5, 0, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 5, 5, "Hello") : ft_printf("%*.*s", 5, 5, "Hello"));
	
	// [J - Tests with n].
return (0);
}
