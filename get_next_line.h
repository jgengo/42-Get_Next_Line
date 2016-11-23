/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:09:44 by jgengo            #+#    #+#             */
/*   Updated: 2016/11/22 14:41:53 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 32

typedef struct				s_gnl
{
	int						fd;
	char					*buff;
}							t_gnl;

int							get_next_line(const int fd, char **line);

#endif
