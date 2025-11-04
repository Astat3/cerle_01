/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:49:04 by agallot           #+#    #+#             */
/*   Updated: 2025/11/04 18:02:43 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (c == '\0')
	{
		return ((char *)s);
	}	
	while (s[i])
	{
		if (s[i] == c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}
