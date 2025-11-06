/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:19:07 by agallot           #+#    #+#             */
/*   Updated: 2025/11/06 02:48:23 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int  ft_strlen(const char *s)
{
	int i;
	
	i = 0;
	while (s[i])
	{
		i++;
	}
	return i;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
char *check_buffer_fill(char *buffer)
{
    char *res;
    int i;

    i = 0;
    res = malloc(sizeof(char ) * (BUFFER_SIZE  + 1));
    if (!res)
        return (NULL);
    while (buffer[i])
    {
        res[i] = buffer[i];
        i++;
    }
    res[i] = '\n';
    return (res);
}
