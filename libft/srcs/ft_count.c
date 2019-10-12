/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:39:02 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:39:05 by alfiumic         ###   ########.fr       */
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
