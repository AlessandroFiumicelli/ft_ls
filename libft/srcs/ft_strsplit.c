/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:59:42 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:59:44 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		wrds;

	wrds = ft_count(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * wrds + 1)))
		return (NULL);
	str = ft_create(s, c, wrds, str);
	return (str);
}
