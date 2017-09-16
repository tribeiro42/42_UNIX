/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:28:45 by tribeiro          #+#    #+#             */
/*   Updated: 2017/02/28 16:30:24 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_error_malloc(char *error)
{
	ft_putendl_fd("Malloc fail -> ", 2);
	ft_putendl_fd(error, 2);
	exit(1);
}

void		ft_error_chdir(char *argv)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd("error: ", 2);
	ft_putendl_fd(argv, 2);
}

void		ft_oldpwdnotset(void)
{
	ft_putendl_fd("OLDPWD NOT SET", 2);
	ft_setoldpwd();
}

int			ft_error_format(char *str)
{
	char		*pos;

	pos = NULL;
	if ((pos = ft_strchr(str, '=')) == 0)
	{
		ft_putendl_fd("USAGE: var=valeur", 2);
		return (1);
	}
	pos = pos + 1;
	if (ft_strchr(pos, '=') == 0)
	{
		return (0);
	}
	ft_putendl_fd("USAGE: var=valeur", 2);
	return (1);
}
