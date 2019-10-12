/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:49:54 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:49:56 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*cur;

	if (len == 0)
		return (s);
	cur = (unsigned char *)s;
	while (len--)
	{
		*cur = (unsigned char)c;
		if (len)
			cur++;
	}
	return (s);
}
