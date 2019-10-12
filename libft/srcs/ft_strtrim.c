/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:00:27 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 12:00:29 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	min_len;
	size_t			max_len;
	char			*str;

	if (!(s))
		return (NULL);
	min_len = 0;
	max_len = ft_strlen(s) - 1;
	if (ft_is_whites(s))
	{
		str = ft_memalloc(1);
		return (str);
	}
	while (s[min_len] == ' ' || s[min_len] == '\n' || s[min_len] == '\t')
		min_len++;
	while (s[max_len] == ' ' || s[max_len] == '\n' || s[max_len] == '\t')
		max_len--;
	if (!(str = ft_strsub(s, min_len, max_len - min_len + 1)))
		return (NULL);
	return (str);
}
