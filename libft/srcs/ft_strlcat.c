/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:55:51 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:55:52 by alfiumic         ###   ########.fr       */
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
