/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:07:05 by jgengo            #+#    #+#             */
/*   Updated: 2016/11/22 16:26:28 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *str, size_t len)
{
	char *copy;

	if (len > ft_strlen(str))
		len = ft_strlen(str);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_strncpy(copy, str, len);
	copy[len] = '\0';
	return (copy);
}
