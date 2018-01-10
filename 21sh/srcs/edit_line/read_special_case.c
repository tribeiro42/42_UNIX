/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_special_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:46:47 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:46:48 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void	read_squote(char tmp, int *statut)
{
	if ((*statut) == 1)
	{
		if (tmp == '\'')
			(*statut) = 0;
	}
	else if (*statut == 0)
	{
		if (tmp == '\'')
			(*statut) = 1;
	}
}

void	read_dquote(char tmp, int *statut)
{
	if ((*statut) == 2)
	{
		if (tmp == '"')
			(*statut) = 0;
	}
	else if ((*statut) == 0)
	{
		if (tmp == '"')
			(*statut) = 2;
	}
}

int		check_special_case(int where, char tmp, int *statut)
{
	if (where == RD_SQUOTE)
		read_squote(tmp, statut);
	else if (where == RD_DQUOTE)
		read_dquote(tmp, statut);
	else if (where == RD_HEREDOC && tmp == EOF)
		return (-1);
	else if (where == RD_ESCAPE && (tmp == '\0' || tmp == '\n'))
		return (-1);
	return (0);
}
