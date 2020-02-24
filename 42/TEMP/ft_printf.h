/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:07:17 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/24 09:01:25 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

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
	struct so_list	*next;
}					to_list;

int						ft_character(char *str, va_list args, to_list *flag);
int 					ft_string(char *str, va_list args, to_list *flag);
int 					ft_integer(char *str, va_list args, to_list *flag, int x);
int 					ft_adress(char *str, va_list args, to_list *flag);
int						ft_hexa(char *str, va_list args, to_list *flag, int *i);
int						ft_percentage(char *str, va_list args, to_list *flag, int x);
int						ft_uint(va_list args, to_list *flag, int x);
int						ft_init_struct(to_list *flag);
void					ft_search_all(char *str, int *i, to_list *flag, va_list args);
int 					ft_find_specifier(char *str, int *i, to_list *flag, va_list args);
int						ft_init_struct(to_list *flag);
char					*ft_convert_base(char *nbr, char *base_form, char *base_to);
char					*ft_itoll(long long n);
long long				checkbase(char *base);
long long				ft_atoll_base(char *str, char *base);
long long				ft_strllen(char *str);
static unsigned int		unbnb(unsigned int nb);
int						mini_atoi(char *str, int *i);
int						ft_width_calc(char *str, int *i, to_list *flag, va_list args);
char					*ft_convert_adress(void const *p);
void					ft_putchar(char c);
void					ft_putnbr(int n);
char					*ft_u_itoa(unsigned int n);

#endif