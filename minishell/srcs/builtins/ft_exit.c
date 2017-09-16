/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:07:39 by tribeiro          #+#    #+#             */
/*   Updated: 2017/02/18 12:50:14 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_exit_error(char **argv)
{
	int		size;

	size = 0;
	size = ft_arraysize_2d(&argv);
	if (size > 2)
	{
		ft_putendl_fd("exit: too many arguments", 2);
		return (1);
	}
	return (0);
}

void			ft_exit(char **argv)
{
	int		ret;

	ret = ft_exit_error(argv);
	ft_arraydel_2d(argv, 0);
	ft_arraydel_2d(g_environ, 0);
	exit(ret);
}
