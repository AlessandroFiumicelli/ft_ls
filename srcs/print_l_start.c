/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:43:30 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/11 17:59:57 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	type(mode_t mode)
{
	if (S_ISDIR(mode))
		ft_putchar('d');
	else if (S_ISLNK(mode))
		ft_putchar('l');
	else if (S_ISBLK(mode))
		ft_putchar('b');
	else if (S_ISCHR(mode))
		ft_putchar('c');
	else if (S_ISSOCK(mode))
		ft_putchar('s');
	else if (S_ISFIFO(mode))
		ft_putchar('p');
	else
		ft_putchar('-');
}

void	stampa_permessi(t_file *files, int i)
{
	t_stat	st;

	lstat(files->path[i], &st);
	type(st.st_mode);
	ft_putchar(S_IRUSR & st.st_mode ? 'r' : '-');
	ft_putchar(S_IWUSR & st.st_mode ? 'w' : '-');
	ft_putchar(S_IXUSR & st.st_mode ? 'x' : '-');
	ft_putchar(S_IRGRP & st.st_mode ? 'r' : '-');
	ft_putchar(S_IWGRP & st.st_mode ? 'w' : '-');
	ft_putchar(S_IXGRP & st.st_mode ? 'x' : '-');
	ft_putchar(S_IROTH & st.st_mode ? 'r' : '-');
	ft_putchar(S_IWOTH & st.st_mode ? 'w' : '-');
	ft_putchar(S_IXOTH & st.st_mode ? 'x' : '-');
	ft_putchar(' ');
	ft_putchar(' ');
}

void	stampa_lnk(t_file *files, int i)
{
	t_stat	st;
	int		len;

	lstat(files->path[i], &st);
	len = (lnk_len(files, st.st_nlink, 1));
	while (len < files->l_len)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putmax(st.st_nlink);
	ft_putchar(' ');
}

void	stampa_user(t_file *files, int i)
{
	char	*tmp;
	t_stat	st;
	int		len;
	t_uid	*us;

	lstat(files->path[i], &st);
	len = usr_len(files, st.st_uid);
	while (len < files->u_len)
	{
		ft_putchar(' ');
		len++;
	}
	us = getpwuid(st.st_uid);
	if (!us)
		tmp = itoa_usr_grp(st.st_uid);
	else
		tmp = ft_strdup(us->pw_name);
	ft_putstr(tmp);
	free(tmp);
	ft_putstr("  ");
}

void	stampa_group(t_file *files, int i)
{
	char	*tmp;
	t_stat	st;
	int		len;
	t_gid	*gr;

	lstat(files->path[i], &st);
	len = grp_len(files, st.st_gid);
	while (len < files->g_len)
	{
		ft_putchar(' ');
		len++;
	}
	gr = getgrgid(st.st_gid);
	if (!gr)
		tmp = itoa_usr_grp(st.st_gid);
	else
		tmp = ft_strdup(gr->gr_name);
	ft_putstr(tmp);
	free(tmp);
	ft_putstr("  ");
}
