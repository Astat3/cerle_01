/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:32:02 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/04 14:27:44 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(const char c, char const *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

//taille du malloc + index début fin
static int	trim_len(char const *s1, char const *sep,
	int *ptr_start, int *ptr_end)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_sep(s1[start], sep))
	{
		start ++;
	}
	while (!(s1[end]) || (is_sep(s1[end], sep) != 0))
	{
		end--;
	}
	*ptr_end = end + 1;
	*ptr_start = start;
	return (end - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		size;
	int		start;
	int		end;
	int		i;

	i = 0;
	size = trim_len(s1, set, &start, &end);
	dest = malloc((sizeof(char)) * (size + 1));
	if (!dest)
		return (NULL);
	while (start < end)
	{
		dest[i++] = s1[start++];
	}
	dest[i] = '\0';
	return (dest);
}

// int main(void)
// {
// 	const char *src = "a  bonjour    a      ";
// 	const char *sep = "a ";
// 	char *dest = ft_strtrim(src,sep);
// 	printf("size %d\n", ft_strlen(src));
// 	printf("%s", dest);
// }