/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:33:33 by tribeiro          #+#    #+#             */
/*   Updated: 2017/03/02 13:28:14 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_initbuildtins(t_builtins *builtins)
{
	builtins[0] = &ft_echo;
	builtins[1] = &ft_cd;
	builtins[2] = &ft_setenv;
	builtins[3] = &ft_unsetenv;
	builtins[4] = &ft_env;
	builtins[5] = &ft_exit;
	builtins[6] = &ft_pwd;
	builtins[NB_BUILTINS] = 0;
}

static void			ft_interpreter_binargv(char *path, char **argv)
{
	pid_t		father;
	int			sig;
	int			ret;

	ret = 0;
	father = fork();
	if (father == 0)
	{
		ret = execve(path, argv, g_environ);
		if (ret < 0)
			ft_putendl_fd("error execve: bin not found", 1);
	}
	signal(SIGINT, SIG_IGN);
	wait(&sig);
}

static void			ft_browse_pathbin(char **path, char **argv)
{
	char		*buf;
	int			i;
	int			v;

	i = 0;
	v = 0;
	buf = NULL;
	while (path[i])
	{
		buf = ft_strjoin(path[i], "/");
		buf = ft_strjoin1(&buf, &(*argv));
		if (access(buf, F_OK) == 0)
		{
			ft_interpreter_binargv(buf, argv);
			ft_strdel(&buf);
			v = 1;
			break ;
		}
		else
			ft_strdel(&buf);
		i++;
	}
	if (v == 0)
		ft_putendl_fd("error bin not found", 1);
}

void				ft_interpreter_bin(char **argv)
{
	char		*env;
	char		**path;
	int			id;

	path = NULL;
	if (ft_strchr(*argv, '/') == 0)
	{
		id = ft_searchenv("PATH=");
		if (id < 0)
		{
			ft_putendl_fd("Bin not found", 2);
			return ;
		}
		env = ft_strsub(g_environ[id], 5, ft_strlen(g_environ[id]));
		path = ft_strsplit(env, ':');
		ft_browse_pathbin(path, argv);
		free(env);
		ft_arraydel_2d(path, 0);
	}
	else
		ft_interpreter_binargv(*argv, argv);
}

void				ft_interpreter_builtins(char **argv)
{
	t_builtins		builtins[NB_BUILTINS + 1];
	int				id;

	id = ft_buildtins_id(*argv);
	if (id >= 0)
	{
		ft_initbuildtins((t_builtins*)builtins);
		builtins[id](argv);
	}
	else
		ft_interpreter_bin(argv);
}
