/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:50:54 by ficoppol          #+#    #+#             */
/*   Updated: 2019/05/28 18:04:27 by filippoma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_count(char const *s, char c)
{
	int wrds;
	int i;

	i = 0;
	wrds = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			wrds++;
		else if (s[i] != c && s[i - 1] == c)
			wrds++;
		i++;
	}
	return (wrds);
}
