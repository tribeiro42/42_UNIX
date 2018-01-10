/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:43:37 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:43:41 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "main.h"

typedef int		(*t_operateur)(char cur);
# define NB_OPERATEUR 9

typedef struct		s_token
{
	int				type;
	char			*data;
	struct s_token	*next;
}					t_token;

/*
** TOOLS
*/

char				**ft_strsplit_lexer(char *s, char c, int mode, int *statut);
char				*split_str(char *s, int len, int mode, int *statut);
/*
** CORE
*/

char				**ft_lexer(char *line);
t_token				*ft_token_recognition(char *line);
int					ft_token_id(char c);

#endif
