/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:46:34 by ficoppol          #+#    #+#             */
/*   Updated: 2019/05/28 18:15:52 by filippoma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;
	size_t d_len;
	size_t s_len;

	src_len = ft_strlen(src);
	dst_len = ft_strnlen(dst, size);
	if (dst_len == size)
		return (src_len + size);
	d_len = dst_len;
	s_len = 0;
	while (s_len < size - dst_len - 1 && src[s_len])
	{
		dst[d_len] = src[s_len];
		d_len++;
		s_len++;
	}
	dst[d_len] = '\0';
	return (dst_len + src_len);
}
