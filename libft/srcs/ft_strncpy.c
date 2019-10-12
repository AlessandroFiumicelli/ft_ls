/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:57:20 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:57:25 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t src_len;

	src_len = 0;
	while (src[src_len] && src_len < len)
	{
		dst[src_len] = src[src_len];
		src_len++;
	}
	while (src_len < len)
	{
		dst[src_len] = '\0';
		src_len++;
	}
	return (dst);
}
