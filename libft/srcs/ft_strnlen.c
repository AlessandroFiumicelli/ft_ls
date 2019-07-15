/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:14:47 by ficoppol          #+#    #+#             */
/*   Updated: 2019/05/28 18:17:50 by filippoma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strnlen(const char *str, size_t n)
{
	size_t len;

	len = 0;
	while (len < n && str[len])
		len++;
	return (len);
}
