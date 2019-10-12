/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:55:36 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:55:38 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	len = ft_cust_strlen(s1) + ft_cust_strlen(s2);
	if (!(str = ft_memalloc(len + 1)))
		return (NULL);
	str = ft_cust_strcpy(str, s1);
	str = ft_cust_strcat(str, s2);
	if (!str)
		return (NULL);
	else
		return (str);
}
