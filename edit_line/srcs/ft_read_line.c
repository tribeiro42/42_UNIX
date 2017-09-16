/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:02:45 by tribeiro          #+#    #+#             */
/*   Updated: 2017/05/12 14:25:13 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*	printf("lines %d\n", w.ws_row);
	printf("columns %d\n", w.ws_col);*/


char			*ft_read_line(void)
{
	char	tmp;
	int		i;
	t_line	l;

	i = 0;
	ft_init_tline(&l);
	while (1)
	{
 		if (i == l.lmax)
			ft_realloc_line(&l);
		if ((read( 1, &tmp, 1)) == 0)
			ft_read_fail(&l.line, "shell: read fail");
		if(ft_isprint(tmp))
			ft_addchar(&i, &l, tmp);
		if(tmp == 27)
			ft_keys_nav(&l, &i, tmp);
		if (tmp == 127)
		  ft_delchar(&l, &i);
		if (tmp == 10)
			break;
		else
			ft_shortcuts_keyboad(&l, &i, tmp);
	}
	ft_strdel(&(l.buf));
	return (l.line);
}

void			ft_keys_nav(t_line *l, int *i, char tmp)
{
	read(0, &tmp, 1);
	if(tmp == '[')
	{
		read(0, &tmp, 1);
		if(tmp == 68 && l->cur > 0)
			ft_left_arrow(l);
		if(tmp == 67 && l->cur < *i)
			ft_right_arrow(l);
		if (tmp == '1')
			ft_maj_keys(l, i, tmp);
		if (tmp == 72)
			ft_go_begin(l);
		if (tmp == 70)
			ft_go_end(l, *i);
		if(tmp == 51)
			ft_delchar_rev(l, i);
	}
}
