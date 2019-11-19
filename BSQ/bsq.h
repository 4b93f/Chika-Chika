/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:07:51 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/19 14:24:36 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef enum 	e_bool
{
	TRUE = 1,
	FALSE = 0
}				t_bool;

typedef struct 	s_struct
{
	
}				t_struct;

char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_verif_map(char **str);
int		ft_atoi(char *str);
char	*ft_recup_code(char *str, char **chaine);
int		ft_verif_cara(char **strs, char *cara);
int		ft_verif_is_only_obs(char **strs, char *cara);
int		ft_verif_if_only_vide(char **strs, char *cara);
int		ft_verif_if_same(char *cara);

#endif