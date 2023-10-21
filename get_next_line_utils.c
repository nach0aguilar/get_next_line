/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:14:41 by igaguila          #+#    #+#             */
/*   Updated: 2023/10/20 15:58:04 by igaguila         ###   ########.fr       */
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
	if (!s1)
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

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*newstring;
	char	chr;

	i = 0;
	chr = (char)c;
	newstring = (char *)s;
	if (!s)
		return (0);
	if (c == '\0')
		return (newstring);
	while (s[i])
	{
		if (s[i] == chr)
			return (&newstring[i]);
		else
			i++;
	}
	if (newstring[i] == chr)
		return (&newstring[i]);
	return (0);
}
