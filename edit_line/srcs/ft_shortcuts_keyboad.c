/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortcuts_keyboad.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:19:52 by tribeiro          #+#    #+#             */
/*   Updated: 2017/05/12 14:31:28 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_shortcuts_keyboad(t_line *l, int *i, char tmp)
{
	if (tmp == 11)
		ft_cut_line(l, i);
	if (tmp == 21)
		ft_past_line(l, i);
	if (tmp == 1)
		ft_go_begin(l);
	if (tmp == 5)
		ft_go_end(l, *i);
}
