/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:24:18 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/14 01:06:05 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *newcontent;

	if (!(newcontent = malloc(sizeof(t_list))))
		return (0);
	newcontent->content = content;
	newcontent->next = NULL;
	return (newcontent);
}
/*
** Ajouter un nouvel élément
*/
