/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:19:07 by agallot           #+#    #+#             */
/*   Updated: 2025/11/08 17:50:58 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int  ft_strlen(const char *s)
{
	int i;
	
	i = 0;
	while (s[i])
	{
		i++;
	}
	return i;
}


char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;
	int		size;

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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*altdst;
	unsigned char	*altsrc;

	altdst = (unsigned char *)dst;
	altsrc = (unsigned char *)src;
	while (n > 0)
	{
		*altdst = *altsrc;
		altdst++;
		altsrc++;
		n--;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (start >= (unsigned)ft_strlen(s))
		len = 0;
	if (len > (size_t) ft_strlen(s))
		len = ft_strlen(s);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while ((i < len) && (s[start]))
	{
		res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}