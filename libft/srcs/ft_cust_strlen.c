/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cust_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:40:10 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:40:13 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_cust_strlen(const char *str)
{
	size_t len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}
