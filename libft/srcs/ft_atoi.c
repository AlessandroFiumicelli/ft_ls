/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:38:17 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:38:41 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		skip_whites(char *str, int i)
{
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'\
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	long int	num;
	int			neg;
	int			i;

	num = 0;
	neg = 1;
	i = skip_whites((char*)str, 0);
	if (str[i] == '-')
		neg = -neg;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return ((int)(num * neg));
}
