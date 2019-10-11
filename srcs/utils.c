/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:44:27 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/11 18:04:54 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*itoa_usr_grp(uintmax_t n)
{
	int			len;
	uintmax_t	tmp;
	char		*ret;

	len = 1;
	tmp = n;
	while (tmp > 9)
	{
		tmp /= 10;
		len++;
	}
	ret = (char*)malloc(sizeof(char) * (len + 1));
	ft_bzero(ret, len + 1);
	len--;
	if (tmp == 0)
		ret[len] = '0';
	while (tmp > 0)
	{
		ret[len] = (tmp % 10) + 48;
		tmp /= 10;
		len--;
	}
	return (ret);
}

void	ft_putmax(uintmax_t n)
{
	if (n > 9)
	{
		ft_putmax(n / 10);
		ft_putchar((n % 10) + 48);
	}
	if (n < 10)
		ft_putchar(n + 48);
}

void	print_path(char *path)
{
	ft_putchar('\n');
	ft_putstr(path);
	ft_putchar(':');
	ft_putchar('\n');
}

void	add_slash(t_file *files)
{
	char	*tmp;

	tmp = ft_strdup(files->d_pth);
	free(files->d_pth);
	files->d_pth = ft_strjoin(tmp, "/");
	free(tmp);
}

void	get_path(t_file *files, char *name)
{
	char	*tmp;

	tmp = name;
	if (name[0] == '/' || (name[0] == '.' &&
	name[1] == '/'))
		files->d_pth = ft_strdup(tmp);
	else if (!ft_strcmp(".", name))
		files->d_pth = ft_strjoin(name, "/");
	else
		files->d_pth = ft_strjoin("./", tmp);
	if (files->d_pth[ft_strlen(files->d_pth) - 1] != '/')
		add_slash(files);
}
