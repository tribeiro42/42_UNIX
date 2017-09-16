/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:16:34 by tribeiro          #+#    #+#             */
/*   Updated: 2017/05/11 20:53:11 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_addchar(int *i, t_line *l, char tmp)
{
	char	*end;

	end = NULL;
	ft_putstr("\033[K");
	end = ft_strdup(&(l->line[l->cur]));
	ft_bzero((&l->line[l->cur]), ft_strlen(&(l->line[l->cur])));
	l->line[l->cur] = tmp;
	ft_strcpy(&(l->line[l->cur + 1]), end);
	ft_strdel(&end);
	write(1, &(l->line[l->cur]), ft_strlen(&(l->line[l->cur])));
	if (l->cur != *i)
		reset_pos(ft_strlen(&(l->line[l->cur])));
	l->cur += 1;
	*i += 1;
}

void		ft_delchar(t_line *l, int *i)
{
	char		*end;

	end = NULL;
	if (l->cur > 0)
	{
		*i -= 1;
		ft_putstr("\033[1D");
		ft_putstr("\033[K");
		end = ft_strdup(&(l->line[l->cur]));
		l->cur -= 1;
		ft_bzero((&l->line[l->cur]), ft_strlen(&(l->line[l->cur])));
		ft_strcpy(&(l->line[l->cur]), end);
		ft_strdel(&end);
		write(1, &(l->line[l->cur]), ft_strlen(&(l->line[l->cur])));
		if (l->cur != *i)
			reset_pos(ft_strlen(&(l->line[l->cur])) + 1);
	}
}

void		ft_delchar_rev(t_line *l, int *i)
{
	char		*end;
	char		tmp;

	end = NULL;
	read(0, &tmp, 1);
	if (l->cur < *i && *i > 0)
	{
		*i -= 1;
		ft_putstr("\033[J");
		end = ft_strdup(&(l->line[l->cur + 1]));
		ft_bzero((&l->line[l->cur]), ft_strlen(&(l->line[l->cur])));
		ft_strcpy(&(l->line[l->cur]), end);
		ft_strdel(&end);
		write(1, &(l->line[l->cur]), ft_strlen(&(l->line[l->cur])));
		if (l->cur != *i)
			reset_pos(ft_strlen(&(l->line[l->cur])) + 1);
	}
}

void		ft_go_begin(t_line *l)
{
	fprintf(l->fd, " / ********************\\ \n");
	fprintf(l->fd, "| --  GO TO BEGIN    -- | \n");
	fprintf(l->fd, " \\ ********************/ \n");
	while(l->cur)
		ft_left_arrow(l);
}

void		ft_go_end(t_line *l, int i)
{
	fprintf(l->fd, " / ********************\\ \n");
	fprintf(l->fd, "| --  GO TO END    -- | \n");
	fprintf(l->fd, " \\ ********************/ \n");
	while(l->cur < i)
		ft_right_arrow(l);
}
