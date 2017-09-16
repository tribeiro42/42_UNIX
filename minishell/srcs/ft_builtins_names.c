/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_names.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:58:01 by tribeiro          #+#    #+#             */
/*   Updated: 2017/02/06 14:49:03 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_initbuildtins_names(char **name)
{
	name[0] = "echo";
	name[1] = "cd";
	name[2] = "setenv";
	name[3] = "unsetenv";
	name[4] = "env";
	name[5] = "exit";
	name[6] = "pwd";
	name[NB_BUILTINS] = 0;
}

int				ft_buildtins_id(char *name)
{
	char		*builtins_name[NB_BUILTINS + 1];
	int			i;

	i = 0;
	ft_initbuildtins_names((char**)builtins_name);
	while (i < NB_BUILTINS)
	{
		if (ft_strcmp(name, builtins_name[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}
