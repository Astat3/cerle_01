/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:52:27 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/06 03:10:31 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

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

int	count_num(long int nbr, char *base)
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

int	print_nbr_base(long unsigned int nbr, char *base)
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
		ft_putchar((nbr % 10) + '0');
	}
	if (nbr >= 10)
	{
		ft_print_nbr(nbr / 10, base);
		ft_putchar((nbr % 10) + '0');
	}
	return (count_num(nbr, base) + temp);
}

int format_sel(char format, va_list *list)
{
	int count;
	
	count = 0;
	if (format == 'c')
		count += print_char(va_arg(*list, int));
	else if(format == 's')
		count += print_string(va_arg(*list, char *));
	else if(format == 'i' || format == 'd')
		count += ft_print_nbr(va_arg(*list, long int), "0123456789");
	else if(format == 'x')
		count += print_nbr_base((unsigned)(va_arg(*list,long int)), "0123456789abcdef");
	else if(format == 'X')
		count += print_nbr_base((unsigned)(va_arg(*list,long int)), "0123456789ABCDEF");
	else if(format == 'u')
		count += ft_print_nbr((unsigned)(va_arg(*list, long int)), "0123456789");
	else if(format == 'p')
		{
			count += print_string("0x");
			count += print_nbr_base((unsigned long long)(va_arg(*list, long int)),"0123456789abcdef");
		}
	else
		count += write(1, &format, 1);
	return (count);
	
}


int	ft_printf(const char *format, ...)
{
	va_list list;
	va_start(list, format);
	int	count;
	int i; 
	
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			{
			count += format_sel(format[++i], &list);				
			}
		else
		{
			count+= write(1, &format[i], 1);
		}
		i++;
	}
	va_end(list);	
	return (count);
}

int main(void)
{
	int count = 0; 
	int og_count = 0;
	count = ft_printf("123%s45\n", (char *) NULL);
	og_count = printf("123%s45\n",(char *)NULL);
	printf("count moi: %d\ncount og: %d\n", count, og_count);
	return 0;
}
