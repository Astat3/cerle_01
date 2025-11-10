/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_others.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:04:58 by agallot           #+#    #+#             */
/*   Updated: 2025/11/10 14:06:12 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_num(long long unsigned int nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr <= 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr > 0)
	{
		count++;
		nbr /= ft_strlen(base);
	}
	return (count);
}

int	print_nbr_base(unsigned long long int nbr, char *base)
{
	unsigned int	size;

	size = ft_strlen(base);
	if (nbr < size)
	{
		ft_putchar(base[(nbr % size)]);
	}
	if (nbr >= size)
	{
		print_nbr_base(nbr / size, base);
		ft_putchar((base[nbr % size]));
	}
	return (count_num(nbr, base));
}

int	ft_print_nbr(long int nbr, char *base)
{
	int	temp;

	temp = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
		temp++;
	}
	if (nbr < 10)
	{
		print_char((nbr % 10) + '0');
	}
	if (nbr >= 10)
	{
		ft_print_nbr(nbr / 10, base);
		ft_putchar((nbr % 10) + '0');
	}
	return (count_num(nbr, base) + temp);
}
