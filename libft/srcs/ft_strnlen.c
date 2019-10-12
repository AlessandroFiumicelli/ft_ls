/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:58:25 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:58:27 by alfiumic         ###   ########.fr       */
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
