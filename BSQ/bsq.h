/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:07:51 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/19 19:46:38 by chly-huc         ###   ########.fr       */
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

typedef enum	e_bool
{
	TRUE = 1,
	FALSE = 0
}				t_bool;

typedef struct	s_square
{
	int		size;
	int		colpos;
	int		lignepos;
}				t_square;

char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_verif_map(char **map);
int		ft_atoi(char *str);
char	*ft_recup_code(char **map);
int		ft_verif_cara(char **map, char *code);
int		ft_verif_is_only_obs(char **map, char *code);
int		ft_verif_if_only_vide(char **map, char *code);
int		ft_verif_if_same(char *code);
char	*ft_check_error(char **map);
int		**ft_map_setup_main(char **map, char *code);
int 	ft_verif_is_toolong(char **map);
t_square	*square_finder(int **map);

#endif
