/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:37:34 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/10/27 11:09:45 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *buffer, char *buff_aux)
{
	char	*temp;

	temp = ft_strjoin(buffer, buff_aux);
	free(buffer);
	buffer = NULL;
	return (temp);
}

static char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	buffer = NULL;
	return (line);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*read_file(int fd, char *buffer)
{
	char	*buff_aux;
	int		byte_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	buff_aux = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buff_aux, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buff_aux);
			buff_aux = NULL;
			return (NULL);
		}
		buff_aux[byte_read] = '\0';
		buffer = ft_free(buffer, buff_aux);
		if (ft_strchr(buff_aux, '\n'))
			break ;
	}
	free(buff_aux);
	buff_aux = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
