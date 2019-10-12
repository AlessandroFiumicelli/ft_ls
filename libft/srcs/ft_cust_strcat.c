/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cust_strcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:39:24 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:39:26 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_cust_strcat(char *dst, const char *src)
{
	int dst_len;
	int src_len;

	if (!dst || !src)
		return (NULL);
	dst_len = 0;
	src_len = 0;
	while (dst[dst_len])
		dst_len++;
	while (src[src_len])
	{
		dst[dst_len] = src[src_len];
		dst_len++;
		src_len++;
	}
	dst[dst_len] = '\0';
	return (dst);
}
