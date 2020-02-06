/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 05:55:47 by chly-huc          #+#    #+#             */
/*   Updated: 2020/02/06 16:11:38 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

# define TRUE 1
# define FALSE 0
# define BASE1 "0123456789abcdef"
# define BASE2 "0123456789ABCDEF"
# define FLAGS "-+ 0"
# define FORMAT "cspdiuxX%%"

typedef struct		so_list
{
	int FLAG_ZERO;
	int FLAG_MINUS;
	int FLAG_DOT;
	int FLAG_STARS;
	struct so_list	*next;
}					to_list;


int 					find_format_id(char *str, va_list ap, to_list *flag);
int						ft_int(char *str);
char					*ft_itoa(int n);
void					ft_string(char *str, va_list ap);
void					ft_putstr_fd(char *s, int fd);
char					*ft_strdup(const char *s);
size_t					ft_strlen(const char *str);
int						ft_integer(char *str, va_list ap, to_list *flag);
int     				ft_char(char *str, va_list ap);
void					ft_putnbr_fd(int n, int fd);
void					ft_putchar_fd(char c, int fd);
int 					ft_unsigned_int(char *str, va_list ap, to_list *flag);
char					*ft_u_itoa(unsigned int n);
static unsigned int		nbnb1(unsigned int nb);
int		nbnb(int nb);
int 					ft_pourcentage(char *str, va_list ap);
char 					*itoa_base(void const *p);
int 					ft_p(char *str, va_list ap);
int 					ft_hexa_caps(char *str, to_list *flag, va_list ap);
int 					ft_hexa_nocaps(char *str, to_list *flag, va_list ap);
char					*ft_convert_base(char *nbr, char *base_form, char *base_to);
void apply_flag(char *str, to_list *flag, int i);
void ft_flag(char *str, to_list *flag);
void ft_flag_zero(char *str, to_list *flag, int nb);
int		ft_strrrchr(const char *s, int c);
int find_flag(char *str, to_list *flag);
int		ft_init_struct(to_list *flag);
void ft_flag_zero1(char *s1, char *s2);
void apply_flag1(char *str, to_list *flag, char *s1);
char			*ft_strjoin(char const *s1, char const *s2);

#endif