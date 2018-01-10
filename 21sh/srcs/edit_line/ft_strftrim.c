/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strftrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:47:14 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:47:15 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		delimiteur(char c)
{
	if (c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

char			*ft_strftrim(char *s)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	ret = NULL;
	if (s && *s)
	{
		i = 0;
		k = 0;
		j = ft_strlen(s);
		while (delimiteur(s[i]))
			i++;
		while (delimiteur(s[j]))
			j--;
		if (!(ret = (char*)malloc(sizeof(char) * (j - i) + 2)))
			return (NULL);
		while (i <= j)
			ret[k++] = s[i++];
		ret[k] = '\0';
	}
	ft_strdel(&s);
	return (ret);
}
