/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:42:12 by chly-huc          #+#    #+#             */
/*   Updated: 2019/11/19 14:24:36 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_check_error(char **strs, char *str)
{
    char *code;
	if ((ft_verif_map(strs)) == 0)
        return (FALSE);
    if ((code = ft_recup_code(str, strs)) == NULL);
        return (FALSE);
    if ((ft_verif_cara(strs, code)) == 0)
        return (FALSE);
    if ((ft_verif_is_only_obs(strs, code)) == 0)
        return (FALSE);
    if ((ft_verif_if_only_vide(strs, code)) == 0)
        return (FALSE);
    if ((ft_verif_if_same(code)) == 0)
        return (FALSE);
    return(TRUE);
}