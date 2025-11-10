/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:19 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/10 14:08:07 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_string(char *s)
{
	int	count;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	count = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}	
	return (count);
}
