/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:44:17 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/11 17:44:19 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	estrazione_2(DIR *dirp, t_flag *flag, t_file *files, int *f_c)
{
	*f_c = files_count(dirp, flag);
	files_init(files, *f_c);
}

void	estrazione(char *name, t_flag *flag, int i)
{
	DIR		*dirp;
	t_dir	*entr;
	t_file	files;
	int		f_c;

	if ((dirp = opendir(name)))
	{
		estrazione_2(dirp, flag, &files, &f_c);
		get_path(&files, name);
		dirp = opendir(name);
		while ((entr = readdir(dirp)))
			riempi_files(&files, flag, entr->d_name);
		closedir(dirp);
	}
	else
	{
		ft_error(name);
		return ;
	}
	if (flag->rec == 1)
		get_crt(&files);
	stampa(&files, flag, -1, i);
	free_all(&files, f_c);
	if (flag->rec == 1)
		recursion(files.crt, flag);
}
