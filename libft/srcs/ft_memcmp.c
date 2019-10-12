/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:49:04 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:49:06 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			len;

	len = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (n--)
	{
		if (str1[len] != str2[len])
			return (str1[len] - str2[len]);
		len++;
	}
	return (0);
}
