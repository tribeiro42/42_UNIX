/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identification_builtins.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:49:21 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:49:22 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static void		ft_builtins_names(char **name)
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

int				ft_identification_builtins(char *token)
{
	char		*builtins_name[NB_BUILTINS + 1];
	int			i;

	i = -1;
	ft_builtins_names((char**)builtins_name);
	while (++i < NB_BUILTINS)
		if (ft_strcmp(token, builtins_name[i]) == 0)
			return (i);
	return (-1);
}
