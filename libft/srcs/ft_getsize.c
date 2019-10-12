/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:42:34 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:42:36 by alfiumic         ###   ########.fr       */
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
