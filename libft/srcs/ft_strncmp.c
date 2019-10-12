/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:57:07 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:57:09 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len;

	len = 0;
	while (len < n && (s1[len] || s2[len]))
	{
		if (s1[len] != s2[len])
			return (*((unsigned char*)s1 + len) - *((unsigned char*)s2 + len));
		len++;
	}
	return (0);
}
