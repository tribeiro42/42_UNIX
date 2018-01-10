/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:46:02 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:46:04 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

char		**ft_arrjoin(char **base, char **add)
{
	int		count;
	int		count2;
	char	**ret;

	if (!(ret = (char**)malloc(sizeof(char*) * \
							(ft_arrlen(base) + \
							ft_arrlen(add) + 1))))
		ft_error_malloc("error in ft_arrfjoin");
	count = 0;
	count2 = 0;
	while (base[count] != NULL)
	{
		ret[count] = ft_strdup(base[count]);
		count++;
	}
	while (add[count2] != NULL)
	{
		ret[count] = ft_strdup(add[count2]);
		count++;
		count2++;
	}
	ret[count] = NULL;
	return (ret);
}

size_t		ft_arrlen(char **array)
{
	size_t	count;

	count = 0;
	if (array == NULL)
		return (0);
	while (array[count] != NULL)
		count++;
	return (count);
}

char		**ft_arrldup(char **arr, size_t max)
{
	size_t	count;
	char	**ret;

	count = 0;
	ret = NULL;
	if (ft_arrlen(arr) < max)
		ret = (char**)malloc(sizeof(char*) * ft_arrlen(arr) + 1);
	else
		ret = (char**)malloc(sizeof(char*) * max + 1);
	if (ret == NULL)
		ft_error_malloc("error in func arrldup");
	while ((arr[count] != NULL) && (count < max))
	{
		ret[count] = ft_strdup(arr[count]);
		count++;
	}
	ret[count] = NULL;
	return (ret);
}
