/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:14:41 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/19 17:33:30 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;
	unsigned int	newlen;

	i = -1;
	j = 0;
    if(!s1)
    {
        s1 = malloc(sizeof(char) * 1);
        s1[0] = '\0';
    }
	newlen = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * newlen + 1);
	if (!new)
		return (NULL);
	while (s1[++i])
		new[i] = s1[i];
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
    free(s1);
	return (new);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = malloc(count * size);
	if (pointer == NULL)
		return (pointer);
	ft_bzero(pointer, count * size);
	return (pointer);
}