/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:59:54 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:59:58 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		str_len;
	int		to_find_len;
	int		tmp_str_len;

	if (to_find[0] == '\0')
		return ((char*)str);
	str_len = 0;
	while (str[str_len])
	{
		to_find_len = 0;
		tmp_str_len = str_len;
		while (str[str_len] == to_find[to_find_len])
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
