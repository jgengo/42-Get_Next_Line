/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 09:18:34 by jgengo            #+#    #+#             */
/*   Updated: 2016/11/23 10:18:02 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl		*gnl_findorcreate_file(const int fd, t_list **my_list)
{
	t_list		*file;
	t_gnl		file_data;

	file = *my_list;
	while (file)
	{
		if (((t_gnl *)(file->content))->fd == fd)
			return (file->content);
		file = file->next;
	}
	file_data.fd = fd;
	file_data.buff = ft_strnew(BUFF_SIZE);
	if (file_data.buff == NULL)
		return (NULL);
	file = ft_lstnew(&file_data, sizeof(file_data));
	if (file == NULL)
		return (NULL);
	ft_lstadd(my_list, file);
	return ((*my_list)->content);
}

static ssize_t		gnl_readoneline(t_gnl *file)
{
	char		read_buffer[BUFF_SIZE + 1];
	ssize_t		size_read;

	size_read = 1;
	while (size_read > 0 && ft_strstr(file->buff, "\n") == NULL)
	{
		size_read = read(file->fd, &read_buffer, BUFF_SIZE);
		if (size_read == -1)
			return (-1);
		read_buffer[size_read] = '\0';
		file->buff = ft_strjoin(file->buff, read_buffer);
		ft_memset(read_buffer, '\0', size_read);
	}
	return (size_read);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*my_list;
	t_gnl			*file;
	ssize_t			buff_read;
	char			*temp;

	if (fd < 0 || !line)
		return (-1);
	file = gnl_findorcreate_file(fd, &my_list);
	if ((buff_read = gnl_readoneline(file)) == -1)
		return (-1);
	*line = ft_strcdup(file->buff, '\n');
	temp = file->buff;
	file->buff = ft_strdup(file->buff + ft_strclen(file->buff, '\n') + 1);
	free(temp);
	return (**line || buff_read > 0 ? 1 : 0);
}
