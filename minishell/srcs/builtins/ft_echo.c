/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:07:01 by tribeiro          #+#    #+#             */
/*   Updated: 2017/02/18 12:52:52 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_search(char *argv)
{
	int		pos;
	int		id;

	pos = ft_strlen(argv);
	id = 0;
	while (g_environ[id] != 0)
	{
		if (ft_strncmp(argv, g_environ[id], pos) == 0)
			return (id);
		id++;
	}
	return (-1);
}

static void		ft_printenv(char *name)
{
	int		id;
	int		size;
	char	*buf;
	char	*result;

	buf = NULL;
	result = NULL;
	size = ft_strlen(name);
	buf = ft_strsub(name, 1, size);
	id = ft_search(buf);
	if (id >= 0)
	{
		result = ft_strsub(g_environ[id], size, ft_strlen(g_environ[id]));
		ft_putstr(result);
		free(result);
	}
	free(buf);
}

void			ft_echo(char **argv)
{
	argv++;
	while (*argv)
	{
		if (ft_strncmp(*argv, "$", 1) == 0)
			ft_printenv(*argv++);
		else
		{
			ft_putstr(*argv++);
			if (*argv)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}
