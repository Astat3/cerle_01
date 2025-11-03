/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:21:24 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/03 18:14:35 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int static	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int static	is_valid(unsigned int size, unsigned int start)
{
	if (size < start)
		return (0);
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (! is_valid(ft_strlen(s), start))
		return (NULL);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
	{
		return (NULL);
	}
	while (i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
