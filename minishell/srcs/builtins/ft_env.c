/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:07:39 by tribeiro          #+#    #+#             */
/*   Updated: 2017/03/02 13:35:42 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_env(char **argv)
{
	pid_t	father;
	int		size;
	int		sig;

	size = ft_arraysize_2d(&argv);
	if (size == 1)
		ft_putendl_array2d(&g_environ);
	if (size > 1)
	{
		if (ft_strchr(*argv, '=') != 0)
		{
			father = fork();
			if (father == 0)
			{
				ft_setenv(argv);
				ft_putendl_array2d(&g_environ);
				ft_exit(argv);
			}
			wait(&sig);
		}
		else
			ft_interpreter_bin(argv);
	}
}
