/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:43:56 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/11 18:02:26 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	get_crt(t_file *files)
{
	t_stat	st;
	int		i;
	int		j;

	i = 0;
	while (files->name[i])
	{
		lstat(files->path[i], &st);
		if ((S_ISDIR(st.st_mode)))
			files->d_n++;
		i++;
	}
	files->crt = (char**)malloc(sizeof(char*) * (files->d_n + 1));
	i = 0;
	j = -1;
	while (files->name[i])
	{
		lstat(files->path[i], &st);
		if (S_ISDIR(st.st_mode) && ft_strcmp(".", files->name[i]) &&
		ft_strcmp("..", files->name[i]))
			files->crt[++j] = ft_strdup(files->path[i]);
		i++;
	}
	files->crt[++j] = NULL;
}

void	recursion(char **dirs, t_flag *flag)
{
	int		i;

	i = -1;
	while (dirs[++i])
	{
		estrazione(dirs[i], flag, 1);
		free(dirs[i]);
	}
	free(dirs);
}
