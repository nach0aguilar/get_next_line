/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:14:38 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/22 14:56:30 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readbuffer(int fd, char *container)
{
	int		bytes;
	char	*buffer;

	bytes = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (!ft_strchr(container, '\n') && (bytes != 0))
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

char	*ft_deleteline(char *container)
{
	char	*newcontainer;
	int		i;
	int		j;

	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (!container[i])
	{
		free(container);
		return (0);
	}
	newcontainer = malloc((ft_strlen(container) - i + 1) * sizeof(char));
	if (!newcontainer)
		return (0);
	i++;
	j = 0;
	while (container[i])
		newcontainer[j++] = container[i++];
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
	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (container[i] && container[i] != '\n')
	{
		line[i] = container[i];
		i++;
	}
	if (container[i] == '\n')
	{
		line[i] = container[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*container[2828];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	container[fd] = ft_readbuffer(fd, container[fd]);
	if (!container[fd])
		return (0);
	line = ft_newline(container[fd]);
	container[fd] = ft_deleteline(container[fd]);
	if (!line || !*line)
	{
		free(line);
		return (0);
	}
	return (line);
}

// int	main(void)
// {
// 	int fd1 = open("archivo1.txt", O_RDONLY);
// 	int fd2 = open("archivo2.txt", O_RDONLY);
// 	int fd3 = open("archivo3.txt", O_RDONLY);

// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd3));

// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd3));

// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// }