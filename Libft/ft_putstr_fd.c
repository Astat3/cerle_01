/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 01:54:10 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/03 16:46:33 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	fputhchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		fputhchar_fd(s[i], fd);
		i++;
	}
}
