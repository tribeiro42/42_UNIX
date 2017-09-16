/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:42:52 by tribeiro          #+#    #+#             */
/*   Updated: 2017/03/02 13:35:42 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

void			sig_handler(int signo)
{
	(void)signo;
	ft_prompt();
}

static void		ft_interpreter(char *cmd)
{
	char				**argv;

	argv = NULL;
	argv = ft_strsplit_blank(cmd);
	if (argv[0] != 0)
		ft_interpreter_builtins(argv);
	ft_arraydel_2d(argv, 0);
}

int				main(void)
{
	extern char			**environ;
	char				*line;
	char				**cmd;
	int					i;

	cmd = NULL;
	g_environ = environ;
	ft_envdup();
	signal(SIGINT, sig_handler);
	while (1)
	{
		i = -1;
		line = NULL;
		ft_prompt();
		ft_read_line(0, &line, 80);
		if (*line != 0)
		{
			cmd = ft_strsplit(line, ';');
			while (cmd[++i] != NULL)
				ft_interpreter(cmd[i]);
			ft_arraydel_2d(cmd, 0);
		}
		ft_strdel(&line);
	}
	return (0);
}
