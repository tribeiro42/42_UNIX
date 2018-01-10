/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_dje.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:52:29 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:52:29 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*ft_get_line2(char *buffer)
{
	int		count;
	char	*tmp;

	count = 0;
	if (buffer)
	{
		while (buffer[count] != '\0')
		{
			if (buffer[count] == '\n')
				break ;
			count++;
		}
		tmp = ft_strsub(buffer, 0, count);
		return (tmp);
	}
	return (NULL);
}

static int	ft_get_save2(char **line, char **s)
{
	(*line) = ft_get_line2(*s);
	(*s) = ft_strfsub2(*s, ft_strnlen(*s, '\n') + 1, ft_strlen2(*s));
	return (1);
}

static int	ft_check_return2(char **save, char **line, int ret)
{
	int		count;

	ft_memdel((void**)line);
	if (ret < 0)
	{
		ft_memdel((void**)save);
		ft_memdel((void**)line);
		return (-1);
	}
	count = ft_strlen(*save);
	if (count == 0)
	{
		ft_memdel((void**)save);
		return (0);
	}
	(*line) = ft_strdup(*save);
	ft_memdel((void**)save);
	return (1);
}

int			ft_gnl(const int fd, char **line)
{
	int			ret;
	static char	*save = NULL;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (ft_strchr(save, '\n'))
		return (ft_get_save2(line, &save));
	if (save == NULL)
		save = ft_strnew(0);
	if (!((*line) = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		malloc_error2("error in func get_next_line", -1);
	while (!(ft_strchr(save, '\n')))
	{
		if ((ret = read(fd, (*line), BUFF_SIZE)) < 1)
			return (ft_check_return2(&save, line, ret));
		(*line)[ret] = '\0';
		save = ft_strjoin_fl2(save, *line);
	}
	*line != NULL ? ft_strdel(line) : NULL;
	(*line) = ft_get_line2(save);
	if ((ft_strchr(save, '\n')) != 0)
		save = ft_strfsub2(save, ft_strnlen(save, '\n') + 1, ft_strlen2(save));
	return ((ret > 1) ? (1) : ret);
}
