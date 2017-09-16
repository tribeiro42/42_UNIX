/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:42:52 by tribeiro          #+#    #+#             */
/*   Updated: 2017/05/11 21:04:21 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

int				main(void)
{
	char				*line;

	while (1)
	{
		line = NULL;
		ft_default_term();
		ft_prompt();
		ft_init_term();
		line = ft_read_line();
		if(line != 0)
		{
			if ((ft_strncmp(line, "exit", 4)) == 0)
			{
				ft_default_term();
				exit(1);
			}
		}
		ft_strdel(&line);
	}
	ft_default_term();
	ft_putendl(line);
	return (0);
}
