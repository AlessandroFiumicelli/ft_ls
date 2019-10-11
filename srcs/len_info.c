/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:41:22 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/11 17:55:09 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		grp_len(t_file *files, gid_t gid)
{
	char	*tmp;
	t_gid	*gr;
	int		chk;

	gr = getgrgid(gid);
	if (!gr)
		tmp = itoa_usr_grp(gid);
	else
		tmp = ft_strdup(gr->gr_name);
	chk = ft_strlen(tmp);
	free(tmp);
	files->g_len = chk > files->g_len ? chk : files->g_len;
	return (chk);
}

int		usr_len(t_file *files, uid_t uid)
{
	char	*tmp;
	t_uid	*us;
	int		chk;

	chk = files->u_len;
	us = getpwuid(uid);
	if (!us)
		tmp = itoa_usr_grp(uid);
	else
		tmp = ft_strdup(us->pw_name);
	chk = ft_strlen(tmp);
	free(tmp);
	files->u_len = chk > files->u_len ? chk : files->u_len;
	return (chk);
}

int		lnk_len(t_file *files, nlink_t lnks, int chk)
{
	while (lnks > 9)
	{
		lnks /= 10;
		chk++;
	}
	files->l_len = chk > files->l_len ? chk : files->l_len;
	return (chk);
}

int		sze_len(t_file *files, off_t size, int chk)
{
	while (size > 9)
	{
		size /= 10;
		chk++;
	}
	files->s_len = chk > files->s_len ? chk : files->s_len;
	return (chk);
}
