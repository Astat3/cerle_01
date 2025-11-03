/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:21:24 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/03 16:50:48 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
	{
		return (NULL);
	}
	while (i < len)
	{
		
	}
}
