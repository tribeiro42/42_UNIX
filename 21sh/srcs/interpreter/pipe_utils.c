/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:49:05 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:49:11 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

void	end_pipe(int last, int *fd)
{
	if (g_backup != 0)
		close(g_backup);
	g_backup = dup(fd[0]);
	if (last == 0)
		close(fd[0]);
}
