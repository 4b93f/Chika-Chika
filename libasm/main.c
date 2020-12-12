/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:01:08 by chly-huc          #+#    #+#             */
/*   Updated: 2020/12/12 17:14:51 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int ft_write(int c , char *str, int e);
int ft_read(unsigned int fd, const char *str, size_t e);
int ft_strlen(const char *str);
int ft_strcmp(const char *s1, const char *s2);

int main()
{
	printf("%d\n", ft_strcmp("OUI", "OUI"));
}