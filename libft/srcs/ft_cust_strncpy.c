/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cust_strncpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:03:48 by ficoppol          #+#    #+#             */
/*   Updated: 2019/05/28 18:05:14 by filippoma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_cust_strncpy(char *dst, const char *src, size_t len)
{
	size_t src_len;

	src_len = 0;
	while (src[src_len] && src_len < len)
	{
		dst[src_len] = src[src_len];
		src_len++;
	}
	while (src_len <= len)
	{
		dst[src_len] = '\0';
		src_len++;
	}
	return (dst);
}
