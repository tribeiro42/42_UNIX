/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:07:39 by tribeiro          #+#    #+#             */
/*   Updated: 2017/02/18 12:53:13 by tribeiro         ###   ########.fr       */
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
		{
			if (g_environ[id][pos] == '=')
				return (id);
		}
		id++;
	}
	return (-1);
}

static int		ft_valid(char **argv)
{
	int		size;

	size = ft_arraysize_2d(&g_environ);
	argv++;
	if (ft_strchr(*argv, '=') == 0)
		return (size);
	ft_arraydel_2d(argv, 1);
	ft_arraydel_2d(g_environ, 1);
	return (1);
}

static void		ft_error(char **argv)
{
	ft_putendl_fd("Malloc fail ->unsetenv", 2);
	ft_arraydel_2d(argv, 1);
	ft_arraydel_2d(g_environ, 1);
	exit(1);
}

void			ft_unsetenv(char **argv)
{
	int			size;
	char		**ptr;
	int			i;
	int			y;
	int			id;

	i = 0;
	y = -1;
	if ((size = ft_valid(argv)) < 0)
		return ;
	if (!(ptr = (char**)malloc(sizeof(char*) * (size))))
		ft_error(argv);
	ptr[size - 1] = NULL;
	argv++;
	if ((id = ft_search(*argv)) < 0)
		return ;
	while (g_environ[++y] != 0)
	{
		if (i == id)
			y++;
		ptr[i++] = g_environ[y];
	}
	free(g_environ[id]);
	free(g_environ);
	g_environ = ptr;
}
