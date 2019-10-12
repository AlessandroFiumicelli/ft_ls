/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:39:13 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:39:16 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_create(char const *s, char c, int wrds, char **str)
{
	int wrdlen;
	int len;
	int i;

	i = 0;
	len = 0;
	while (i < wrds)
	{
		while (s[len] && s[len] == c)
			len++;
		wrdlen = ft_wordlen(&s[len], c);
		if (!(str[i] = (char*)malloc(sizeof(char) * wrdlen + 1)))
			return (NULL);
		str[i] = ft_cust_strncpy(str[i], &s[len], wrdlen);
		i++;
		len = len + wrdlen;
	}
	str[i] = NULL;
	return (str);
}
