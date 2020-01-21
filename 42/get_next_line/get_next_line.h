/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:34:53 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/21 06:18:33 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

int 	get_next_line(int fd, char **line);
char	*ft_strcpy(char *dest, char *src);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strdup(const char *s);
void	ft_putendl_fd(char *s, int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *dest, char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putendl(char const *s);
void			ft_putstr_fd(char *s, int fd);
char	*ft_strrchr(const char *s, int c);



#endif