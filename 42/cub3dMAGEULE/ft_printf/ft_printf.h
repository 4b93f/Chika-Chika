/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:07:17 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/03 16:20:09 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

# define BASE1 "0123456789abcdef"
# define BASE2 "0123456789ABCDEF"
# define NUMBER "0123456789"
# define FLAGS "0-+ "
# define FORMAT "cspdiuxX%%"

typedef struct		s_flag
{
	int				zero;
	int				minus;
	int				dot;
	int				stars;
	int				width;
	int				preci;
	int				v_p;
	int				preci_neg;
	int				error;
	struct s_flag	*next;
}					t_flag;

int					ft_printf(const char *str, ...);
int					ft_character(va_list args, t_flag *flag);
int					ft_string(va_list args, t_flag *flag, int x);
int					ft_integer(va_list args, t_flag *flag,
						int x, long long nb);
int					ft_adress(va_list args, t_flag *flag);
int					ft_hexa(va_list args, t_flag *flag, int x);
int					ft_percentage(t_flag *flag);
int					ft_uint(va_list args, t_flag *flag, int nb_space);
int					ft_init_struct(t_flag *flag);
int					ft_search_all(char *str, int *i,
						t_flag *flag, va_list args);
int					ft_find_specifier(char *str, int *i,
						t_flag *flag, va_list args);
int					ft_init_struct(t_flag *flag);
char				*ft_convert_base(char *nbr, char *base_form,
						char *base_to);
char				*ft_itoll(long long n);
long long			checkbase(char *base);
long long			ft_atoll_base(char *str, char *base);
long long			ft_strllen(char *str);
int					mini_atoi(char *str, int *i);
int					ft_width_calc(char *str, int *i, va_list args);
void				ft_putchar(char c);
void				ft_putnbr(long long n);
char				*ft_u_itoa(unsigned int n);
int					ft_hexa_caps(va_list args, t_flag *flag, int i);
long long			nbnb(long long nb);
int					unbnb(unsigned long long nb);
void				ft_putunbr(unsigned long long n);
long				ft_power(long n, long pow);
char				*ft_strrev(char *str);
void				specific_parameters(t_flag *flag, int *nb0,
						int *nb_space, int *to_print);
int					ft_strcmp(char *s1, char *s2);
#endif
