/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:46:59 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:47:01 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*area;

	if (!(area = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(area, size);
	return (area);
}
