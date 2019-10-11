/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:41:13 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/11 17:53:09 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file	*free_all(t_file *files, int f_c)
{
	int		i;

	i = 0;
	while (i <= f_c)
	{
		free(files->name[i]);
		free(files->s_lnk[i]);
		free(files->path[i]);
		i++;
	}
	free(files->d_pth);
	free(files->name);
	free(files->s_lnk);
	free(files->path);
	return (files);
}

void	nullifica(t_file *files, int f_c)
{
	int		i;

	i = 0;
	while (i <= f_c)
	{
		files->name[i] = NULL;
		files->s_lnk[i] = NULL;
		files->path[i] = NULL;
		i++;
	}
	files->crt = NULL;
}

void	files_init(t_file *files, int f_c)
{
	files->name = (char**)malloc(sizeof(char*) * (f_c + 1));
	files->s_lnk = (char**)malloc(sizeof(char*) * (f_c + 1));
	files->path = (char**)malloc(sizeof(char*) * (f_c + 1));
	nullifica(files, f_c);
	files->d_n = 0;
	files->t_blck = 0;
	files->l_len = 0;
	files->u_len = 0;
	files->g_len = 0;
	files->s_len = 0;
	files->time = time(&files->time);
}

int		files_count(DIR *dirp, t_flag *flag)
{
	t_dir	*entr;
	int		f_c;

	f_c = 0;
	while ((entr = readdir(dirp)))
	{
		if (entr->d_name[0] == '.' && flag->hid == 1)
			f_c++;
		else if (entr->d_name[0] != '.')
			f_c++;
	}
	closedir(dirp);
	return (f_c);
}
