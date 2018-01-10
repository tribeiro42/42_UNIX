/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraysize_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:29:56 by tribeiro          #+#    #+#             */
/*   Updated: 2017/01/30 17:36:46 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_arraysize_2d(char ***array)
{
	char	**tmp;
	size_t	size;

	size = 0;
	tmp = *array;
	while (*array && **array)
	{
		size++;
		(*array)++;
	}
	*array = tmp;
	return (size);
}
