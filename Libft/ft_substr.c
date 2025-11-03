/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:21:24 by adamgallot        #+#    #+#             */
/*   Updated: 2025/10/21 21:32:29 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *res;
	int	i;

	i = 0;
	res = malloc(sizeof(char) * (len + 1));
	if(!res)
	{
		return (NULL);
	}
	while (i< len)
	{
		/* code */
	}
	
	
}