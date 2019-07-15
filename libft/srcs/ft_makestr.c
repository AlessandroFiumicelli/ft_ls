/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:02:09 by ficoppol          #+#    #+#             */
/*   Updated: 2019/05/28 18:07:47 by filippoma        ###   ########.fr       */
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
