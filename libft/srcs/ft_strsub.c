/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:00:10 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 12:00:12 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!(s) || !(str = ft_memalloc(len + 1)))
		return (NULL);
	while (len > 0)
	{
		str[i] = s[start + i];
		i++;
		len--;
	}
	return (str);
}
