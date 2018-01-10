/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 22:04:40 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:52:44 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_searchenv(char *argv)
{
	int	pos;
	int	id;

	pos = ft_strchr(argv, '=') - argv;
	id = 0;
	while (g_environ[id] != 0)
	{
		if (ft_strncmp(argv, g_environ[id], pos + 1) == 0)
			return (id);
		id++;
	}
	return (-1);
}

int		ft_search(char *argv)
{
	int	pos;
	int	id;

	pos = ft_strlen(argv);
	id = 0;
	while (g_environ[id] != 0)
	{
		if (ft_strncmp(argv, g_environ[id], pos) == 0)
		{
			if (g_environ[id][pos] == '=')
				return (id);
		}
		id++;
	}
	return (-1);
}
