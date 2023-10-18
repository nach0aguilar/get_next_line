/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:14:38 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/18 12:32:05 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int     ft_lenline(char *buffer)
{
    int i;

    i = 0;
    while (buffer[i] != '\n')
        i++;
    return (i);
}

char    *ft_line(char *buffer)
{
    char    *line;
    int     i;
    
    line = malloc(sizeof(char) * (ft_lenline(buffer) + 1));
    i = 0;
    while (buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] = 0;
    return (line);
}

char    *get_next_line(int fd)
{
    char    *buffer;
    char    *line;
    
    buffer = malloc(sizeof(char) * (100 + 1));
    read(fd, buffer, sizeof(buffer));
    line = ft_line(buffer);
    return (line);
}

int main()
{
    int fd = open("archivo.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
}