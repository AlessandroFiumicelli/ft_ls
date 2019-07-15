/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:18:40 by ficoppol          #+#    #+#             */
/*   Updated: 2019/05/28 18:08:49 by filippoma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str_dst;
	unsigned char	*str_src;

	if (n == 0 || dst == src)
		return (dst);
	str_dst = (unsigned char*)dst;
	str_src = (unsigned char*)src;
	while (n--)
		*str_dst++ = *str_src++;
	return ((void*)dst);
}
