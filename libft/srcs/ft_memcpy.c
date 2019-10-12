/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:49:23 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:49:25 by alfiumic         ###   ########.fr       */
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
