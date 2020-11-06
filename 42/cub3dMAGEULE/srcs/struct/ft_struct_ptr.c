/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:35:57 by chly-huc          #+#    #+#             */
/*   Updated: 2020/11/06 16:49:17 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_ptr	ft_create_ptr(void)
{
	t_ptr ptr;

	ptr.mlx_txt = NULL;
	ptr.mlx_txtdata = NULL;

	return (ptr);
}

t_ptr	*ft_malloc_ptr(void)
{
	t_ptr *malloc_ptr;

	if (!(malloc_ptr = malloc(sizeof(t_ptr))))
		ft_error(MALLOC_ERROR);
	*malloc_ptr = ft_create_ptr();
	return (malloc_ptr);
}