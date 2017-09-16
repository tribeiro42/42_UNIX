/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_blank.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:39:16 by tribeiro          #+#    #+#             */
/*   Updated: 2017/03/02 13:34:34 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_del(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int		str_nbr_word(char *str)
{
	int		nbr_word;
	int		i;

	nbr_word = 0;
	i = 0;
	while (str[i])
	{
		if (i == 0 && is_del(str[i]) == 0)
			nbr_word++;
		else if (is_del(str[i - 1]) == 1 && is_del(str[i]) == 0)
			nbr_word++;
		i++;
	}
	return (nbr_word);
}

static char		*ft_sncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	lenght;
	char			*d;

	d = dest;
	lenght = 0;
	while (src[lenght])
		lenght++;
	while (n--)
	{
		if (*src)
			*dest++ = *src++;
		else
			*dest++ = '\0';
	}
	*dest = '\0';
	return (d);
}

static int		str_len(char *str)
{
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (is_del(str[i]) == 0 && str[i])
	{
		i++;
		size++;
	}
	return (size);
}

char			**ft_strsplit_blank(char const *s)
{
	char	**dest;
	int		len;
	int		i;
	int		i2;
	int		size;

	i = 0;
	i2 = 0;
	size = str_nbr_word((char*)s);
	dest = (char **)malloc(sizeof(char*) * (size + 1));
	if (s == 0 || dest == NULL)
		return (NULL);
	while (i2 < size)
	{
		while (is_del(s[i]) == 1)
			i++;
		len = str_len((char *)&s[i]);
		dest[i2] = (char *)malloc(sizeof(char) * (len + 1));
		ft_sncpy(dest[i2], (char*)s + i, len);
		i += len;
		i2++;
	}
	dest[i2] = 0;
	return (dest);
}
