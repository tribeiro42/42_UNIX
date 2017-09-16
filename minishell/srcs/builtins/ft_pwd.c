/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:37:55 by tribeiro          #+#    #+#             */
/*   Updated: 2017/02/18 12:50:23 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_pwd(char **argv)
{
	char		*cwd;
	char		*buf;

	argv++;
	if (*argv)
	{
		if (!(ft_strcmp(*argv, "-") == 0 || ft_strcmp(*argv, "--") == 0))
		{
			ft_putendl_fd("pwd: too many arguments", 2);
			return ;
		}
	}
	buf = NULL;
	cwd = getcwd(buf, 0);
	ft_putendl(cwd);
	free(cwd);
}
