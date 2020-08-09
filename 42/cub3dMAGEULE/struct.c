/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:37:15 by root              #+#    #+#             */
/*   Updated: 2020/08/08 16:23:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_params
{
  int resx;
  int resy;
  char *textno;
  char *textso;
  char *textwe;
  char *textea;
  char *textsp;
  char *textp;
  char *textc;
}              t_params;

t_params ft_create_struct(void)
{
    t_params params;
    params.resx = 0;
    params.resy = 0;
    params.textno = NULL;
    params.textso = NULL;
    params.textwe = NULL;
    params.textea = NULL;
    params.textsp = NULL;
    params.textp = NULL;
    params.textc = NULL;
}

t_params *ft_malloc_struct(void)
{
    t_params *malloc_struct;
    malloc_struct = malloc(sizeof(t_params));
    *malloc_struct = ft_create_struct();
    return(malloc_struct);
}

void ft_free_struct(t_params *to_free)
{
    free(to_free);
}

int ft_init_params()
{
    t_params *params;
    params = ft_malloc_struct();
    ft_free_struct(params);
    return(0);
}