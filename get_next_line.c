/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:14:38 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/19 13:32:54 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char    *ft_readbuffer(int fd, char *container)
{
    char    *buffer;
    
    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return (0);
    read(fd, buffer, BUFFER_SIZE);
    container = ft_strjoin(container, buffer);
    free(buffer);
    return (container);    
}

int     ft_lenline(char *container)
{
    int i;

    i = 0;
    while (container[i] || container[i] == '\n')
        i++;
    return (i);
}

char    *ft_newline(char *container)
{
    int     i;
    char    *line;
    
    line = malloc(sizeof(char) * ft_lenline(container) + 1);
    if (!line)
        return (0);
    i = 0;
    while (container[i] || container[i] == '\n')
    {
        line[i] = container[i];
        i++;
    }
    line[i] = 0;
    return (line);
}

char    *ft_deleteline(char *container)
{
    char    *newcontainer;
    int     i;
    int     j;

    newcontainer = malloc(sizeof(char) * BUFFER_SIZE + 1 - ft_lenline(container));
    if (!newcontainer)
        return (0);
    i = ft_lenline(container);
    j = 0;
    while (container[i])
    {
        newcontainer[j] = container[i];
        j++;
        i++;
    }
    newcontainer[j] = 0;
    free (container);
    return (newcontainer);
}

char    *get_next_line(int fd)
{
    static char *container;
    char        *line;

    if (!container)
        container = ft_readbuffer(fd, container);
    line = ft_newline(container);
    container = ft_deleteline(container);
    return (line);
}

int main()
{
    int fd = open("archivo.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    close (fd);
}