/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:12:57 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/03 16:25:52 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*placeholder;

	placeholder = (unsigned char *)b;
	while (len > 0)
	{
		*placeholder = (unsigned char)c;
		placeholder++;
		len--;
	}
	return (b);
}

static void	*og_alloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (!res)
		return (NULL);
	ft_memset(res, 0, size);
	return (res);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	return (og_alloc(size * nmemb));
}
