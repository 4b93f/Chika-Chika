/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:15:13 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/12 01:17:46 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
	return ;
}
/*
** Ecrire une chaine de caractère dans un fichier donné
*/
