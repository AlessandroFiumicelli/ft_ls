/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sorter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:42:52 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/11 17:42:56 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	sort_args(char **args)
{
	char	*tmp;
	int		i;

	i = 0;
	while (args[i + 1])
	{
		if (ft_strcmp(args[i], args[i + 1]) > 0)
		{
			tmp = args[i];
			args[i] = args[i + 1];
			args[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void	reverse_files(t_flag *flag)
{
	char	*tmp;
	int		min;
	int		max;

	min = 0;
	max = 0;
	while (flag->args[max + 1])
		max++;
	while (min < max)
	{
		tmp = flag->args[min];
		flag->args[min] = flag->args[max];
		flag->args[max] = tmp;
		min++;
		max--;
	}
}

void	reverse_dirs(t_flag *flag)
{
	char	*tmp;
	int		min;
	int		max;

	min = 0;
	max = 0;
	while (flag->dirs[max + 1])
		max++;
	while (min < max)
	{
		tmp = flag->dirs[min];
		flag->dirs[min] = flag->dirs[max];
		flag->dirs[max] = tmp;
		min++;
		max--;
	}
}
