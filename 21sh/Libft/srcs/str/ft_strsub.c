/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:53:13 by tribeiro          #+#    #+#             */
/*   Updated: 2017/02/25 12:01:34 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*ptr;
	size_t	i;

	i = 0;
	dst = NULL;
	if (s)
	{
		if (!(dst = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ptr = dst;
		while (i < len)
		{
			ptr[i] = s[start + i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (dst);
}
