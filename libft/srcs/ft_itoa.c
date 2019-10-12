/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:44:58 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:45:02 by alfiumic         ###   ########.fr       */
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
