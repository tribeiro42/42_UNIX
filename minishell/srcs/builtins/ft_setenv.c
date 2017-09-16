/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:07:39 by tribeiro          #+#    #+#             */
/*   Updated: 2017/03/02 13:35:35 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_searchenv(char *argv)
{
	int		pos;
	int		id;

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

static void		ft_dupsetenv(char **ptr, char *argv, int id)
{
	int		i;

	i = 0;
	while (g_environ[i])
	{
		if (id != -1 && i == id)
		{
			ptr[id] = ft_strdup(argv);
			free(g_environ[i]);
			i++;
			continue ;
		}
		ptr[i] = g_environ[i];
		i++;
	}
}

void			ft_setenv(char **argv)
{
	int			size;
	char		**ptr;
	int			id;

	if (ft_arraysize_2d(&argv) < 2)
		return ;
	if (ft_error_format(argv[1]) == 1)
		return ;
	size = ft_arraysize_2d(&g_environ);
	if (!(ptr = (char**)malloc(sizeof(char*) * (size + 2))))
		ft_error_malloc("setenv");
	ptr[size + 1] = NULL;
	argv++;
	id = ft_searchenv(*argv);
	ft_dupsetenv(ptr, *argv, id);
	if (id < 0)
		ptr[size] = ft_strdup(*argv);
	free(g_environ);
	g_environ = ptr;
}
