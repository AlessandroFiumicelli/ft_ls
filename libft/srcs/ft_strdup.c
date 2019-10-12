/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:54:12 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 11:54:14 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;

	if (!(cpy = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	cpy = ft_strcpy(cpy, str);
	return (cpy);
}
