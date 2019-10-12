/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cust_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:39:48 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:39:51 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_cust_strcpy(char *dst, const char *src)
{
	int	len;

	if (!dst || !src)
		return (NULL);
	len = 0;
	while (src[len])
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = '\0';
	return (dst);
}
