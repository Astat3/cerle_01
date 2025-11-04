/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:49:04 by agallot           #+#    #+#             */
/*   Updated: 2025/11/04 18:54:04 by adamgallot       ###   ########.fr       */
/*                                                                       n     */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;	
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
		return ((char *) (s + i));
	}
	return (NULL);
}
