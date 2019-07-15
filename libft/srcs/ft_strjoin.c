/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:40:24 by ficoppol          #+#    #+#             */
/*   Updated: 2019/05/28 18:13:34 by filippoma        ###   ########.fr       */
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
