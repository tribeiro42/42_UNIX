/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 18:42:52 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 18:42:55 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "main.h"

typedef struct		s_hered
{
	char			*data;
	struct s_hered	*next;
}					t_hered;

typedef struct		s_r
{
	int				fd;
	int				r_fd;
	int				r_close;
	int				red;
	int				error;
	char			*file;
	struct s_r		*next;
}					t_r;

#endif
