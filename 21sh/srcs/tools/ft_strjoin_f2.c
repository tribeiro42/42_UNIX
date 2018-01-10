/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:52:37 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:52:40 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char		*ft_strjoin_f0(char *s1, char *s2)
{
	return (ft_strjoin(s1, s2));
}

char		*ft_strjoin_f2(char *s1, char *s2)
{
	char *ret;

	ret = NULL;
	ret = ft_strjoin(s1, s2);
	ft_strdel(&s2);
	return (ret);
}

char		*ft_strjoin_f1(char *s1, char *s2)
{
	char	*ret;

	ret = NULL;
	ret = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (ret);
}
