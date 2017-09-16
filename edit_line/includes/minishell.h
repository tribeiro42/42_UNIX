/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:46:53 by tribeiro          #+#    #+#             */
/*   Updated: 2017/05/12 14:20:50 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** LIBFT
*/
# include "libft.h"


# include <sys/types.h>
# include <sys/uio.h>

# include <term.h>
# include <ncurses.h>

# include <unistd.h>

#include <sys/ioctl.h>

/*
**  DEBIAN
*/

# include <sys/types.h>
# include <sys/wait.h>


void			ft_prompt(void);
void			prompt(void);

void			ft_init_term(void);
void			ft_default_term(void);


typedef struct	s_line
{
	struct	winsize	w;
	int		cur;
	int		lmax;
	char	*line;
	char	*buf;
	int		prompt_size;
	FILE	*fd;
}				t_line;

char			*ft_read_line(void);
void			ft_init_tline(t_line *l);
void			ft_realloc_line(t_line *l);

void			ft_read_fail(char **line, char *txt);

void			reset_pos(int i);

void			ft_keys_nav(t_line *l, int *i, char tmp);
void			ft_maj_keys(t_line *l, int *i, char tmp);

void			ft_right_arrow(t_line *l);
void			ft_left_arrow(t_line *l);
void			ft_top_arrow(t_line *l);
void			ft_down_arrow(t_line *l, int i);

void			ft_maj_left_arrow(t_line *l);
void			ft_maj_right_arrow(t_line *l, int i);
void			ft_maj_top_arrow(t_line *l);
void			ft_maj_down_arrow(t_line *l, int i);

void			ft_addchar(int *i, t_line *l, char tmp);
void			ft_delchar(t_line *l, int *i);
void			ft_delchar_rev(t_line *l, int *i);

void			ft_go_end(t_line *t, int i);
void			ft_go_begin(t_line *t);

void			ft_shortcuts_keyboad(t_line *l, int *i, char tmp);
void			ft_cut_line(t_line *l, int *i);
void			ft_past_line(t_line *l, int *i);
#endif
