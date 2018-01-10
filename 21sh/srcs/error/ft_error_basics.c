/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_basics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:48:42 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:48:44 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_error_create(char *error, char *file)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd(" -> ", 2);
	ft_putendl_fd(file, 2);
}

void		ft_error_open(char *error)
{
	ft_putstr_fd("21sh: Open fail -> ", 2);
	ft_putendl_fd(error, 2);
	exit(1);
}

void		ft_error_malloc(char *error)
{
	ft_putstr_fd("21sh: Malloc fail -> ", 2);
	ft_putendl_fd(error, 2);
	exit(1);
}

void		ft_error_bin(char *prog)
{
	ft_putstr_fd("error: ", 2);
	ft_putstr_fd(prog, 2);
	ft_putendl_fd(" : not found", 2);
	exit(-1);
}
