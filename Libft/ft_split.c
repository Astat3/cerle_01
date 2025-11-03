/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:13:20 by adamgallot        #+#    #+#             */
/*   Updated: 2025/10/13 16:31:37 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	static ft_is_sep(char c, char sep);

int static count_words(char const *str, char sep)
{
	int	i;
	int	token;
	int	is_token;

	i = 0;
	token = 0;
	is_token = 0;
	while (str[i])
	{
		while (str[i] && ft_is_sep(str[i], sep))
			i++;
		is_token = 0;
		while (str[i] && !(ft_is_sep(str[i], sep)))
		{
			if (is_token == 0)
			{
				is_token = 1;
				token++;
			}
			i++;
		}
	}
	return (token);
}

int static ft_is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

char static *ft_strdup(char const *src, int start, int end)
{
	char	*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(char) * ((end - start) + 1));
	if (arr == NULL)
		return (NULL);
	while (i < end - start)
	{
		arr[i] = src[start + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char **ft_split(char const *s, char c)
{
	int		i;
	char	**tab;
	int		row;
	int		start;

	i = 0;
	row = 0;
	start = 0;
	tab = malloc(((count_words(s, c) + 1)* sizeof(char *))) ;
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] && ft_is_sep(s[i], c))
			i++;
		start = i;
		while (s[i] && !(ft_is_sep(s[i], c)))
			i++;
		if (start < i)
			tab[row++] = ft_strdup(s, start, i);
	}
	tab[row] = NULL;
	return (tab);
}