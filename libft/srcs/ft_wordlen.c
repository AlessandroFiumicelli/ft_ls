/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:48:09 by ficoppol          #+#    #+#             */
/*   Updated: 2019/05/28 18:18:51 by filippoma        ###   ########.fr       */
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
