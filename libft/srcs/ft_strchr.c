/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:52:57 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:52:59 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	check;
	int		len;

	len = 0;
	check = (char)c;
	while (str[len])
	{
		if (str[len] == check)
			return ((char*)&str[len]);
		len++;
	}
	if (check == '\0')
		return ((char*)&str[len]);
	return (NULL);
}
