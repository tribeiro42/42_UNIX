/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_readline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:48:21 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:48:24 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void	free_readline(t_line *line)
{
	if (line->buf != NULL)
		ft_strdel(&line->buf);
	if (line->buf_hist != NULL)
		ft_strdel(&line->buf_hist);
}
