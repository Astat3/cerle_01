/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:19 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/09 18:27:44 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i] , 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int print_char(int c)
{
	return (write(1, &c ,1));
}
int	print_string(char *s)
{
	int	count;

	if (!s)
	{
		ft_putstr("(null)");
		return 6;	
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

int	count_num(long long unsigned int nbr, char *base)
{
	int	count; 
	
	count = 0;
	if(nbr <= 0)
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
	if(nbr < 0)
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