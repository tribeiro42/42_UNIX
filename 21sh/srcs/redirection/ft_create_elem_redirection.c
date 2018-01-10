/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:27:12 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:51:12 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_r		*ft_create_elem_redirection(int red, int fd)
{
	t_r		*elem;

	elem = NULL;
	if (!(elem = (t_r*)malloc(sizeof(t_r))))
		ft_error_malloc("malloc -> t_r");
	elem->red = red;
	elem->fd = fd;
	elem->r_fd = -1;
	elem->r_close = -1;
	elem->file = NULL;
	elem->next = NULL;
	return (elem);
}
