/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:48:53 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:48:55 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str_s;
	unsigned char	check;
	size_t			len;

	str_s = (unsigned char*)s;
	check = (unsigned char)c;
	len = 0;
	while (n--)
	{
		if (str_s[len] == check)
			return (&str_s[len]);
		len++;
	}
	return (NULL);
}
