/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:07:17 by chly-huc          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/02/29 03:11:36 by chly-huc         ###   ########.fr       */
=======
/*   Updated: 2020/03/01 04:00:04 by chly-huc         ###   ########.fr       */
>>>>>>> f7653d0aa2f48bba2bdeabb371e5ddf9149e5e90
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0
# define BASE1 "0123456789abcdef"
# define BASE2 "0123456789ABCDEF"
# define NUMBER "0123456789"
# define FLAGS "0-+ "
# define FORMAT "cspdiuxX%%"

typedef struct		so_list
{
	int FLAG_ZERO;
	int FLAG_MINUS;
	int FLAG_DOT;
	int FLAG_STARS;
	int FLAG_NBR;
	int WIDTH;
	int PRECISION;
	int V_P;
<<<<<<< HEAD
=======
	int PRECI_NEG;
>>>>>>> f7653d0aa2f48bba2bdeabb371e5ddf9149e5e90
	struct so_list	*next;
}					to_list;

int						ft_character(va_list args, to_list *flag);
int 					ft_string(va_list args, to_list *flag, int x);
int 					ft_integer(va_list args, to_list *flag, int x, long long nb);
int 					ft_adress(va_list args, to_list *flag);
int						ft_hexa(va_list args, to_list *flag, int x);
<<<<<<< HEAD
int						ft_percentage(to_list *flag, int x);
=======
int						ft_percentage(to_list *flag);
>>>>>>> f7653d0aa2f48bba2bdeabb371e5ddf9149e5e90
int				ft_uint(va_list args, to_list *flag, int nb_space);
int						ft_init_struct(to_list *flag);
void					ft_search_all(char *str, int *i, to_list *flag, va_list args);
int 					ft_find_specifier(char *str, int *i, to_list *flag, va_list args);
int						ft_init_struct(to_list *flag);
char					*ft_convert_base(char *nbr, char *base_form, char *base_to);
char					*ft_itoll(long long n);
long long				checkbase(char *base);
long long				ft_atoll_base(char *str, char *base);
long long				ft_strllen(char *str);
int						mini_atoi(char *str, int *i);
int						ft_width_calc(char *str, int *i, va_list args);
void					ft_putchar(char c);
void					ft_putnbr(long long n);
char					*ft_u_itoa(unsigned int n);
int						ft_hexa_caps(va_list args, to_list *flag, int i);
long long				nbnb(long long nb);
int			unbnb(unsigned long long nb);
void	ft_putunbr(unsigned long long n);
long	ft_power(long n, long pow);
char	*ft_strrev(char *str);

#endif