/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:41:44 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/11 17:41:46 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int argc, char **argv)
{
	t_flag	flag;

	flag_init(&flag);
	if (argc > 1)
		parser(&flag, argv);
	estrazione(".", &flag, 0);
	return (1);
}
