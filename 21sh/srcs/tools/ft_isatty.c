/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isatty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:52:49 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:52:50 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_isatty(void)
{
	if (isatty(0) == 0)
	{
		ft_putendl_fd("shell: is not tty", 2);
		exit(1);
	}
	g_fd_term = dup(0);
	return (0);
}