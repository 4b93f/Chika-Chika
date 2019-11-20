/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:42:12 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/19 21:58:12 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char		*ft_check_error(char **map)
{
	char *code;

	if ((ft_verif_map(map)) == 0)
		return (NULL);
	code = ft_recup_code(map);
	if (code == NULL)
		return (NULL);
	if ((ft_verif_cara(map, code)) == 0)
		return (NULL);
	if ((ft_verif_is_only_obs(map, code)) == 0)
		return (NULL);
	if ((ft_verif_if_only_vide(map, code)) == 0)
		return (NULL);
	if ((ft_verif_if_same(code)) == 0)
		return (NULL);
	if ((ft_verif_is_toolong(map)) == 0)
		return (NULL);
	return (code);
}
