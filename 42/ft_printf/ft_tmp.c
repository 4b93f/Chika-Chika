/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:01:48 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/14 17:24:59 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + '0');
	}
}

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

void integer(va_list args, int *p)
{
    int in;

    in = va_arg(args, int);
    ft_putnbr(in);
}

void character(va_list args, int *p)
{
    int in;

    in = va_arg(args, int);
    write(1, &in, 1); 
}

void strings(va_list args, int *p)
{
    char *in;

    in = va_arg(args, char*);
    ft_putstr(in);
    write(1, "\n", 1);
}

void adress(va_list args, int *p)
{
    char *in;
    in = va_arg(args, void*);
    in = ft_strjoin("0x", itoa_base(in));
    ft_putstr(in);
}

void unsigned_int(va_list args, int *p)
{
    unsigned long long in;

    in = va_arg(args, int);
    ft_putstr((ft_u_itoa(in)));
    write(1, "\n", 1);
}

void hexa1(va_list args, int *p)
{
    char *in;

    in = ft_itoa(va_arg(args, int));
    in = ft_convert_base(in, "0123456789", BASE1);
    ft_putstr(in);
}

void hexa2(va_list args, int *p)
{
    char *in;

    in = ft_itoa(va_arg(args, int));
    in = ft_convert_base(in, "0123456789", BASE2);
    ft_putstr(in);
}

void ft_parsing(int *i, char *str, va_list args, int *p)
{
    *i = *i + 1;
    str[*i] == '0' ? flag_zero(i, str, args, p) : 0;
    str[*i] > '0' && str[*i] <= 9 ? flag_num(i, str, args, p) : 0;
    str[*i] == 'c' ? character(args, p) : 0;
    str[*i] == 's' ? strings(args, p) : 0;
    str[*i] == 'p' ? adress(args, p) : 0;
    str[*i] == 'd' ? integer(args, p) : 0 || str[*i] == 'i' ? integer(args, p) : 0;
    str[*i] == 'u' ? unsigned_int(args, p) : 0;
    str[*i] == 'x' ? hexa1(args, p) : 0 || str[*i] == 'X' ? hexa2(args, p) : 0;
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int p;
    
    i = 0;
    p = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%')
            ft_parsing(&i, (char*)str, args, &p);
        else
            write(1, &str[i], 1);
        i++;
    }
    va_end(args);
    return (1);
}

int main()
{
    int c = 'e';
    int x = 15;
    char str[] = "OUI";
    char const *p;
    printf("%050x\n", x);
    ft_printf("%050x\n", x);
}