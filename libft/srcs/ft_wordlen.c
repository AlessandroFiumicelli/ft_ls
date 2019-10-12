/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:01:00 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 12:01:02 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_wordlen(char const *s, char c)
{
	int wrdlen;

	wrdlen = 0;
	while (s[wrdlen] && s[wrdlen] != c)
		wrdlen++;
	return (wrdlen);
}
