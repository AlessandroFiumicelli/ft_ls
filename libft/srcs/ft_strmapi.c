/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:56:38 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:56:41 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	len;

	if (!(s))
		return (NULL);
	len = 0;
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[len])
	{
		str[len] = (f)(len, (char)s[len]);
		len++;
	}
	return (str);
}
