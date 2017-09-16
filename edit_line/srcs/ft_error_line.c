/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:53:39 by tribeiro          #+#    #+#             */
/*   Updated: 2017/04/22 19:57:54 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_read_fail(char **line, char *txt)
{
	ft_putendl_fd(txt, 2);
	free(*line);
	ft_default_term();
	exit(1);
}
