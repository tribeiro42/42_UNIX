/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_arrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:40:07 by tribeiro          #+#    #+#             */
/*   Updated: 2017/05/11 20:07:22 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_right_arrow(t_line *l)
{
	fprintf(l->fd, " / ******************** \\ \n");
	fprintf(l->fd, "| --  RIGTH ARROW    --  | \n");
	fprintf(l->fd, " \\ ******************** / \n");
	fprintf(l->fd, "\n\t l->cur = %i\n", (l->cur));
	l->cur += 1;
	fprintf(l->fd, "\t l->cur = %i\n", (l->cur));
	fprintf(l->fd, "\t l->w.ws_col = %i\n", (l->w.ws_col));
	fprintf(l->fd, "\t l->line = %s\n\n", (l->line));

	if (((l->cur + l->prompt_size) % l->w.ws_col) == 0)
	{
		fprintf(l->fd, "NEXT LINE\n");
		ft_putstr("\033[1E");
	}
	else
		ft_putstr("\033[1C");
}

void		ft_left_arrow(t_line *l)
{
	fprintf(l->fd, " / ******************** \\ \n");
	fprintf(l->fd, "| --  LEFT ARROW   --    | \n");
	fprintf(l->fd, " \\ ******************** / \n");
	fprintf(l->fd, "\n\t l->cur = %i\n", (l->cur));

	l->cur -= 1;

	fprintf(l->fd, "\t l->cur = %i\n", (l->cur));
	fprintf(l->fd, "\t l->w.ws_col = %i\n", (l->w.ws_col));
	fprintf(l->fd, "\t l->line = %s\n\n", (l->line));
	/*	if (((l->cur ) % l->w.ws_col) == 0)
	{
		fprintf(l->fd, "PREV LINE\n");
		ft_putstr("\033[1F");
	}
	else*/
		ft_putstr("\033[1D");
}
