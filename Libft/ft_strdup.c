/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:06:16 by adamgallot        #+#    #+#             */
/*   Updated: 2025/10/11 01:55:25 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char *ft_strdup(const char *s)
{
	int i; 
	char *dest;
	int size;
	
	i = 0;
	size = ft_strlen(s);
	dest = malloc((sizeof(char)) * (size + 1));
	if (!dest)
	{
		return (NULL);
	}
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main (void)
{
	char *src = "Bonjour";
	char *dest = ft_strdup(src);
	printf("%s\n", dest);
}