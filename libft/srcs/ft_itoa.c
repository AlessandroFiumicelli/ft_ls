/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:42:31 by ficoppol          #+#    #+#             */
/*   Updated: 2019/05/28 18:06:23 by filippoma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_itoa(int n)
{
	char		*str;
	int			size;
	long int	conv;
	int			neg;

	neg = 0;
	size = 0;
	conv = n;
	if (n < 0)
	{
		conv = -conv;
		size = ft_getsize(conv);
		size++;
		neg = 1;
	}
	else
		size = ft_getsize(n);
	if (!(str = ft_memalloc(size + 1)))
		return (NULL);
	str = ft_makestr(str, size, conv, neg);
	return (str);
}
