/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortcuts_keyboad.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:47:25 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:47:27 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void		ft_shortcuts_keyboard(t_line *l, int *i, char tmp)
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
