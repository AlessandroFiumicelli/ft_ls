/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:16:14 by ficoppol          #+#    #+#             */
/*   Updated: 2019/05/28 18:18:30 by filippoma        ###   ########.fr       */
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
