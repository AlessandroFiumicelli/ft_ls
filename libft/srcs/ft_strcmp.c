/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:01:38 by ficoppol          #+#    #+#             */
/*   Updated: 2019/06/01 14:21:28 by filippoma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int len;

	len = 0;
	if (!s1 || !s2)
		return (0);
	while (*(s1 + len) && *(s1 + len) == *(s2 + len))
	{
		len++;
	}
	return (*((unsigned char*)s1 + len) - *((unsigned char*)s2 + len));
}
