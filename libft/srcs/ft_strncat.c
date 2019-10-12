/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:56:52 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:56:56 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	size_t dst_len;
	size_t src_len;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len])
		dst_len++;
	while (src_len < len && src[src_len])
	{
		dst[dst_len] = src[src_len];
		dst_len++;
		src_len++;
	}
	dst[dst_len] = '\0';
	return (dst);
}
