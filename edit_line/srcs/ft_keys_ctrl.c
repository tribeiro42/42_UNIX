/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_ctrl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 21:05:16 by tribeiro          #+#    #+#             */
/*   Updated: 2017/05/12 15:47:06 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_past_line(t_line *l, int *i)
{
	char	*end;

	end = NULL;
	fprintf(l->fd, " / ******************** \\ \n");
	fprintf(l->fd, "| --   PAST LINE       -- | \n");
	fprintf(l->fd, " \\ ******************** / \n");

	fprintf(l->fd, "\t l->line = %s\n", (l->line));
	fprintf(l->fd, "\t l->buf = %s\n", (l->buf));
	fprintf(l->fd, "\t l->cur = %i\n", (l->cur));
	fprintf(l->fd, "\t i = %d\n\n", (*i));

	if (l->buf != NULL)
	{
		end = ft_strjoin(l->buf, &(l->line[l->cur]));
		fprintf(l->fd, "\t buf != NULL\n end = %s \n\n", end);
		ft_bzero((&l->line[l->cur]), ft_strlen(&(l->line[l->cur])));
		*i += ft_strlen(l->buf);
		while (*i >= l->lmax)
			ft_realloc_line(l);
		ft_strcpy(&(l->line[l->cur]), end);
		ft_strdel(&end);
		ft_putstr("\033[J");
		write(1, &(l->line[l->cur]), ft_strlen(&(l->line[l->cur])));
		l->cur += ft_strlen(l->buf);
		if (l->cur != *i)
			reset_pos(ft_strlen(&(l->line[l->cur])) + 1);

	}
	fprintf(l->fd, "\t l->line = %s\n", (l->line));
	fprintf(l->fd, "\t l->buf = %s\n", (l->buf));
	fprintf(l->fd, "\t l->cur = %i\n", (l->cur));
	fprintf(l->fd, "\t i = %d\n\n", (*i));
}

void			ft_cut_line(t_line *l, int *i)
{
	fprintf(l->fd, " / ******************** \\ \n");
	fprintf(l->fd, "| --    CUT LINE       -- | \n");
	fprintf(l->fd, " \\ ******************** / \n");

	fprintf(l->fd, "\t l->line = %s\n", (l->line));
	fprintf(l->fd, "\t l->buf = %s\n", (l->buf));
	fprintf(l->fd, "\t l->cur = %i\n", (l->cur));
	fprintf(l->fd, "\t i = %d\n\n", (*i));

	if (l->buf != NULL)
		ft_strdel(&(l->buf));
	l->buf = ft_strdup(&(l->line[l->cur]));
	*i -= ft_strlen(l->buf);
	ft_bzero((&l->line[l->cur]), ft_strlen(&(l->line[l->cur])));
	ft_putstr("\033[J");

	fprintf(l->fd, "\t l->line = %s\n", (l->line));
	fprintf(l->fd, "\t l->buf = %s\n", (l->buf));
	fprintf(l->fd, "\t l->cur = %i\n", (l->cur));
	fprintf(l->fd, "\t i = %d\n\n", (*i));
}

