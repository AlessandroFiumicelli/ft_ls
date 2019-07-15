/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:03:47 by ficoppol          #+#    #+#             */
/*   Updated: 2019/05/28 18:05:22 by filippoma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_getsize(long int nb)
{
	size_t size;

	size = 0;
	if (nb == 0)
	{
		size++;
		return (size);
	}
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}
