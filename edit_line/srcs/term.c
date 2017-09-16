/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 12:26:02 by tribeiro          #+#    #+#             */
/*   Updated: 2017/04/07 14:54:18 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_error(char *line)
{
	ft_putendl_fd(line, 2);
	ft_default_term();
	exit(1);
}

void		ft_init_term(void)
{
	struct termios      attr;
	char				*ret;

	if ((ret = getenv("TERM")) == NULL)
		ft_error("shell: getenv null");
	if (tgetent(NULL, ret) == ERR)
		ft_error("shell: tgetent err");
	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag &= ~(ECHO | ICANON);
	attr.c_oflag &= ~(OPOST);
	attr.c_cc[VMIN] = 1;
	attr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &attr);
}

void		ft_default_term(void)
{
	struct termios      attr;

	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag |= (ECHO | ICANON);
	attr.c_oflag |= (OPOST);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &attr);
}
