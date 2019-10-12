/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:53:25 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:53:27 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int len;

	len = 0;
	if (!s1 || !s2)
		return (0);
	while (*(s1 + len) && *(s1 + len) == *(s2 + len))
	{
		len++;
	}
	return (*((unsigned char*)s1 + len) - *((unsigned char*)s2 + len));
}
