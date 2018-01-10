/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:50:38 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:50:39 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		error_redirection(char *s, int count)
{
	ft_putstr_fd("syntax error near unexpected token : '", 2);
	ft_putchar_fd(s[count], 2);
	ft_putendl_fd("'", 2);
	return (-2);
}

int		is_left(char *s, int count)
{
	int ret;

	ret = -1;
	if (s[count] == '<')
	{
		ret = 1;
		if (s[++count])
		{
			if (s[count] == '<')
				ret = 2;
			else if (s[count] == '>')
				ret = 5;
			if (s[++count])
			{
				if (s[count] == '<' || s[count] == '>')
					return (error_redirection(s, count));
			}
		}
	}
	return (ret);
}

int		is_right(char *s, int count)
{
	int ret;

	ret = -1;
	if (s[count] == '>')
	{
		ret = 3;
		if (s[++count])
		{
			if (s[count] == '>')
				ret = 4;
			if (s[++count])
			{
				if (s[count] == '<' || s[count] == '>')
					return (error_redirection(s, count));
			}
		}
	}
	return (ret);
}

int		ft_isredirection(char *s, int count)
{
	int	ret;

	ret = -1;
	if (s[count])
	{
		if (s[count] == '<')
			ret = is_left(s, count);
		else if (s[count] == '>')
			ret = is_right(s, count);
	}
	return (ret);
}
