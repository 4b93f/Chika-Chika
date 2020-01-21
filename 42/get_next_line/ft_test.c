/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 04:28:29 by chly-huc          #+#    #+#             */
/*   Updated: 2020/01/21 06:30:47 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 69 

void save(const char *str)
{
	char *save;
	char *tmp;
	save = (char*)str;
	tmp = save;
	printf("%s\n", tmp);
}

int main()
{
	save("non");
}