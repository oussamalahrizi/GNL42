/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:23:53 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/29 19:07:27 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*update_holder(char *holder)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (holder[i] && holder[i] != '\n')
		i++;
	if (!holder[i])
	{
		free(holder);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(holder) - i + 1));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (holder[i])
		new[j++] = holder[i++];
	new[j] = 0;
	free(holder);
	return (new);
}

char	*read_line(char *holder)
{
	char	*line;
	int		i;

	i = 0;
	if (!holder[i])
		return (NULL);
	while (holder[i] && holder[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (holder[i] && holder[i] != '\n')
	{
		line[i] = holder[i];
		i++;
	}
	if (holder[i] == '\n')
	{
		line[i] = holder[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*join_holder(int fd, char *holder)
{
	char	*buff;
	int		readed;

	if (!holder)
		holder = reset_c(1, 1);
	readed = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!search(holder, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			free(holder);
			return (NULL);
		}
		buff[readed] = 0;
		holder = join_strs(holder, buff);
		if (!holder)
			return (NULL);
	}
	free(buff);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*holder[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	holder[fd] = join_holder(fd, holder[fd]);
	if (!holder[fd])
		return (NULL);
	line = read_line(holder[fd]);
	holder[fd] = update_holder(holder[fd]);
	return (line);
}
