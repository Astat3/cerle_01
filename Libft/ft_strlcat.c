/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:19:47 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/04 14:47:51 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat( char *dst, const char *src, size_t size )
{
	size_t	i;
	size_t	j;
	size_t	l_src;

	i = 0;
	j = 0;
	l_src = ft_strlen(src);
	while (i < size && dst[i])
	{
		i++;
	}
	if (i < size)
	{
		return (l_src + size);
	}
	while (j < size - i - 1)
	{
		dst[i] = src[j];
	*dst = '\0';
		return (i + j);
	}
	return (0);
}
