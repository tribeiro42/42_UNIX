/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:22:26 by tribeiro          #+#    #+#             */
/*   Updated: 2017/05/11 21:06:09 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_init_tline(t_line *l)
{
	ioctl(0, TIOCGWINSZ, &(l->w));

	l->cur = 0;
	l->lmax = 256;
	if(!(l->line = (char*)malloc(l->lmax)))
		ft_read_fail(NULL, "shell: malloc fail -> line buffer");
	ft_bzero(l->line, l->lmax);
	l->buf = NULL;
	l->fd = fopen("log.txt", "w+");
	l->prompt_size = 5;
}

void			ft_realloc_line(t_line *l)
{
	fprintf(l->fd, " / ******************** \\ \n");
	fprintf(l->fd, "| --  REALOC LINE      -- | \n");
	fprintf(l->fd, " \\ ******************** / \n");

	fprintf(l->fd, "\t l->line = %s\n", (l->line));
	fprintf(l->fd, "\t l->cur = %i\n", (l->cur));
	fprintf(l->fd, "\t l->max = %i\n\n", (l->lmax));
	l->line = ft_realloc_char(l->line, l->lmax + 256);
	l->lmax += 255;
	if (l->line == NULL)
		ft_read_fail(&(l->line), "shell: NULL -> read_line");
	ft_bzero(&(l->line[l->cur]), (l->lmax - l->cur));
	fprintf(l->fd, "\t l->line = %s\n", (l->line));
	fprintf(l->fd, "\t l->cur = %i\n", (l->cur));
	fprintf(l->fd, "\t l->max = %i\n\n", (l->lmax));
}

void			reset_pos(int i)
{
	while(--i > 0)
		ft_putstr("\033[1D");
}
