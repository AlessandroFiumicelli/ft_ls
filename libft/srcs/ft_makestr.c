/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:46:46 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:46:47 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_makestr(char *str, size_t size, long int conv, int neg)
{
	size = size - 1;
	if (conv == 0)
		str[0] = '0';
	else
	{
		while (conv > 0)
		{
			if (neg)
				str[0] = '-';
			str[size] = (char)((conv % 10) + 48);
			conv = conv / 10;
			size--;
		}
	}
	return (str);
}
