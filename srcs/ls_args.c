/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:41:31 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/11 17:41:35 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	riempi_files_arg(t_file *files, char *path)
{
	char	buf[NAME_MAX];
	t_stat	st;
	int		i;

	i = 0;
	while (files->name[i])
		i++;
	lstat(path, &st);
	files->name[i] = ft_strdup(path);
	files->path[i] = ft_strdup(path);
	if (S_ISLNK(st.st_mode))
	{
		ft_bzero(&buf, NAME_MAX);
		readlink(path, buf, NAME_MAX);
		files->s_lnk[i] = ft_strdup(buf);
	}
	sizes(files, &st);
}

void	stampa_files_l(t_flag *flag)
{
	t_file	files;
	int		i;

	i = -1;
	files_init_args(&files, flag);
	while (flag->args[++i])
		riempi_files_arg(&files, flag->args[i]);
	i = -1;
	while (files.name[++i])
	{
		stampa_permessi(&files, i);
		stampa_lnk(&files, i);
		stampa_user(&files, i);
		stampa_group(&files, i);
		stampa_size(&files, i);
		stampa_tempo(&files, i);
		ft_putstr(files.name[i]);
		if (files.s_lnk[i])
			stampa_slink(&files, i);
		else
			ft_putchar('\n');
	}
	free_files_args(&files, flag);
}

void	stampa_files(t_flag *flag)
{
	int		i;

	if (flag->l_f == 0)
	{
		i = -1;
		while (flag->args[++i])
			ft_putendl(flag->args[i]);
	}
	else
		stampa_files_l(flag);
}

void	ls_args(t_flag *flag)
{
	int		i;

	if (flag->args[0])
		stampa_files(flag);
	if (flag->dirs[0])
	{
		i = -1;
		while (flag->dirs[++i])
			estrazione(flag->dirs[i], flag, 1);
	}
	free_flag(flag);
	exit(1);
}
