/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:46:53 by tribeiro          #+#    #+#             */
/*   Updated: 2017/03/02 13:38:32 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/*
**  DEBIAN
*/

# include <sys/types.h>
# include <sys/wait.h>

typedef void	(*t_builtins) (char **argv);
char			**g_environ;

# define NB_BUILTINS 7

void			ft_envdup(void);

void			ft_prompt(void);
int				ft_read_line(int fd, char **line, int buf);

void			ft_interpreter_builtins(char **argv);
void			ft_interpreter_bin(char **argv);
int				ft_buildtins_id(char *name);

int				ft_searchenv(char *argv);
void			ft_setoldpwd(void);

void			ft_echo(char **argv);
void			ft_cd(char **argv);
void			ft_setenv(char **argv);
void			ft_unsetenv(char **argv);
void			ft_env(char **argv);
void			ft_exit(char **argv);
void			ft_pwd(char **argv);

char			**ft_strsplit_blank(char const *s);

/*
**	ERROR
*/

void			ft_error_malloc(char *error);
void			ft_oldpwdnotset(void);
void			ft_error_chdir(char *argv);
int				ft_error_format(char *str);
#endif
