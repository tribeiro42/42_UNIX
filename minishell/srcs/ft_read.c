/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 13:40:13 by tribeiro          #+#    #+#             */
/*   Updated: 2017/02/18 13:00:51 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	ft_read_fail(char **buf)
{
	ft_putendl_fd("read fail", 2);
	free(buf);
	exit(1);
}

int				ft_read_line(int fd, char **line, int buf_size)
{
	char	*buf;
	char	*tmp;
	int		ret;

	if (!(buf = (char*)malloc(sizeof(char) * (buf_size))))
		exit(1);
	ret = read(fd, buf, buf_size);
	if (ret < 0)
		ft_read_fail(&buf);
	while (0 < ret && buf[ret - 1] != 10)
	{
		buf[ret - 1] = 0;
		tmp = ft_strjoin(*line, buf);
		ft_strdel(line);
		*line = tmp;
		ret = read(fd, buf, buf_size);
	}
	buf[ret - 1] = 0;
	tmp = ft_strjoin(*line, buf);
	ft_strdel(line);
	*line = tmp;
	ft_strdel(&buf);
	return (ret);
}
