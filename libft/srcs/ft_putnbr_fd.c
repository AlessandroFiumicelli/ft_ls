/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:51:51 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:51:54 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int nb;

	if (n == -2147483648)
	{
		ft_putnbr_fd(-2, fd);
		nb = 147483648;
	}
	else if (n < 0)
	{
		nb = -n;
		ft_putchar_fd('-', fd);
	}
	else
		nb = n;
	if (nb == 0)
		ft_putchar_fd('0', fd);
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(((nb % 10) + 48), fd);
	}
	else if (nb < 10)
		ft_putchar_fd((nb + 48), fd);
}
