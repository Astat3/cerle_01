/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:01:29 by adamgallot        #+#    #+#             */
/*   Updated: 2025/10/13 16:03:52 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static fputhchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		fputhchar_fd(s[i], fd);
		i++;
	}
    write(1, "\n", 1);
}

int main(void)
{
    ft_putendl_fd("Bonjour", 1);
}