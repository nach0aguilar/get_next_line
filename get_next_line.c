/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:14:38 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/20 13:46:14 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_readbuffer(int fd, char *container)
{
    int     bytes;
	char	*buffer;
    
    bytes = 1;
	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
    while (!ft_strchr(container, '\n') && bytes != 0)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes == -1)
        {
            free(buffer);
            free(container);
            return (0);
        }
        buffer[bytes] = 0;
        container = ft_strjoin(container, buffer);
    }
	free(buffer);
	return (container);
}

int	ft_lenline(char *container)
{
	int	i;

	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	return (i);
}

char	*ft_deleteline(char *container)
{
	char	*newcontainer;
	int		i;
	int		j;

	newcontainer = calloc(BUFFER_SIZE - ft_lenline(container),
			sizeof(char));
	i = ft_lenline(container) + 1;
	j = 0;
	while (container[i])
		newcontainer[j++] = container[i++];
    if (!newcontainer)
    {
        free(newcontainer);
        return (0);
    }
	newcontainer[j] = 0;
	free(container);
	return (newcontainer);
}

char	*ft_newline(char *container)
{
	int		i;
	char	*line;

    if (!container)
		return (0);
	line = calloc(ft_lenline(container) + 2, sizeof(char));
	i = 0;
	while (container[i] && container[i] != '\n')
	{
		line[i] = container[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	container = ft_readbuffer(fd, container);
	if (!container)
		return (0);
	line = ft_newline(container);
	container = ft_deleteline(container);
    if (!line || !*line)
    {
        free(line);
        return(0);
    }
	return (line);
}

int main()
{
    int fd = open("archivo.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    close (fd);
}