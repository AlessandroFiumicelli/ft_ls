/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:47:09 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:47:14 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str_dst;
	unsigned char	*str_src;
	unsigned char	*ret;
	unsigned char	check;
	size_t			len;

	len = 0;
	check = (unsigned char)c;
	str_dst = (unsigned char*)dst;
	str_src = (unsigned char*)src;
	while (n > 0)
	{
		str_dst[len] = str_src[len];
		if (str_dst[len] == check)
		{
			ret = &str_dst[len + 1];
			return ((void*)ret);
		}
		len++;
		n--;
	}
	return (NULL);
}
