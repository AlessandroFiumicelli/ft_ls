/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ficoppol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:46:43 by ficoppol          #+#    #+#             */
/*   Updated: 2019/06/07 20:00:37 by filippoma        ###   ########.fr       */
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
