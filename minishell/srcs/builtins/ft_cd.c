/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:07:13 by tribeiro          #+#    #+#             */
/*   Updated: 2017/02/18 12:56:56 by tribeiro         ###   ########.fr       */
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

void			ft_setoldpwd(void)
{
	int			id;
	char		*cwd;
	char		*buf;
	char		**oldpwd;

	buf = NULL;
	cwd = getcwd(buf, 0);
	id = ft_search("OLDPWD");
	if (id < 0)
	{
		buf = ft_strdup("OLDPWD= ");
		oldpwd = ft_strsplit(buf, ' ');
		ft_setenv(oldpwd);
		free(buf);
		ft_arraydel_2d(oldpwd, 0);
	}
	else
	{
		ft_strdel(&g_environ[id]);
		buf = ft_strdup("OLDPWD=");
		g_environ[id] = ft_strmerge(&buf, &cwd);
		free(cwd);
	}
}

static void		ft_cd_home(void)
{
	int			ret;
	int			id;
	char		*buf;

	buf = NULL;
	id = ft_search("HOME");
	if (id < 0)
		ft_putendl_fd("minishell: cd: OLDPWD not set", 2);
	else
	{
		buf = ft_strsub(g_environ[id], 5, (ft_strlen(g_environ[id]) - 1));
		ret = chdir(buf);
		if (ret < 0)
			ft_error_chdir("HOME");
		free(buf);
	}
}

static void		ft_cd_oldpwd(char **argv)
{
	int			ret;
	int			id;
	char		*cwd;
	char		*buf;

	buf = NULL;
	cwd = getcwd(buf, 0);
	id = ft_search("OLDPWD");
	if (id < 0)
		ft_oldpwdnotset();
	else
	{
		buf = ft_strsub(g_environ[id], 7, (ft_strlen(g_environ[id]) - 1));
		ret = chdir(buf);
		if (ret < 0)
			ft_error_chdir("OLDPWD");
		free(g_environ[id]);
		free(buf);
		buf = ft_strdup("OLDPWD=");
		g_environ[id] = ft_strmerge(&buf, &cwd);
		free(buf);
		free(cwd);
		ft_pwd(argv);
	}
}

void			ft_cd(char **argv)
{
	int		ret;
	int		size;

	size = ft_arraysize_2d(&argv);
	if (size > 2)
	{
		ft_putendl_fd("cd: too many arguments", 2);
		return ;
	}
	if (size > 1)
		argv++;
	if (ft_strcmp(*argv, "-") == 0)
		ft_cd_oldpwd(argv);
	else if ((ft_strcmp(*argv, "--") == 0) || size == 1)
		ft_cd_home();
	else
	{
		ft_setoldpwd();
		ret = chdir(*argv);
		if (ret < 0)
			ft_error_chdir(*argv);
	}
}
