/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:41:04 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/11 17:45:57 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_error(char *name)
{
	char	*err;
	char	*er1;

	ft_putchar('\n');
	er1 = NULL;
	err = strerror(errno);
	if (!ft_strcmp(err, "Bad file descriptor"))
		er1 = ft_strdup("directory causes a cycle");
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	if (er1)
		ft_putendl_fd(er1, 2);
	else
		ft_putendl_fd(err, 2);
	free(er1);
}

void	ls_error(char *str, char opt)
{
	if (!(ft_strcmp(str, "ILLEGAL")))
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putchar_fd(opt, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ls [-Ralrt] [file ...]", 2);
		exit(1);
	}
}
