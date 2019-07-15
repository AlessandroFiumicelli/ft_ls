/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:21:15 by ficoppol          #+#    #+#             */
/*   Updated: 2019/05/28 18:17:56 by filippoma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t str_len;
	size_t to_find_len;
	size_t tmp_str_len;

	if (!ft_strlen(to_find))
		return ((char*)str);
	str_len = 0;
	while (str_len < len && str[str_len])
	{
		to_find_len = 0;
		tmp_str_len = str_len;
		while (str_len < len && str[str_len] == to_find[to_find_len])
		{
			str_len++;
			to_find_len++;
			if (to_find[to_find_len] == '\0')
				return ((char*)&str[tmp_str_len]);
		}
		str_len = tmp_str_len;
		str_len++;
	}
	return (NULL);
}
