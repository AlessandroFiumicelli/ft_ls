/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:01:19 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 15:11:00 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_line_maker(char **str, char **line, int ret, int fd);

static int	ft_line_maker(char **str, char **line, int ret, int fd)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str[fd][len] && str[fd][len] != '\n')
		len++;
	if (str[fd][len])
	{
		*line = ft_strsub(str[fd], 0, len);
		tmp = ft_strdup(&str[fd][len + 1]);
		free(str[fd]);
		str[fd] = tmp;
	}
	else
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[4096] = {NULL};
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!str[fd] || !str[fd][0]))
		return (0);
	return (ft_line_maker(str, line, ret, fd));
}
