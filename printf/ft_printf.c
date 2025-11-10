/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:52:27 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/10 14:14:36 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

int	print_ptr(void *ptr)
{
	int					count;
	unsigned long long	p_val;

	p_val = 0;
	count = 0;
	if (ptr == NULL)
		count += print_string("(nil)");
	else
	{
		p_val = (unsigned long long)ptr;
		count += print_string("0x");
		count += print_nbr_base(p_val, "0123456789abcdef");
	}
	return (count);
}

int	format_sel(char format, va_list *list)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(*list, int));
	else if (format == 's')
		count += print_string(va_arg(*list, char *));
	else if (format == 'i' || format == 'd')
		count += ft_print_nbr((long)va_arg(*list, int), "0123456789");
	else if (format == 'x')
		count += print_nbr_base((unsigned)(va_arg(*list, long int)),
				"0123456789abcdef");
	else if (format == 'X')
		count += print_nbr_base((unsigned)(va_arg(*list, long int)),
				"0123456789ABCDEF");
	else if (format == 'u')
		count += ft_print_nbr((unsigned)(va_arg(*list, long int)),
				"0123456789");
	else if (format == 'p')
	{
		count += print_ptr(va_arg(*list, void *));
	}
	else
		count += write(1, &format, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		count;
	int		i;

	va_start(list, format);
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
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(list);
	return (count);
}

// int main(void)
// {
//     int og_count;
// 	int count;

// 	int *p;
// 	int a = 100;

// 	p = &a;
//     og_count = printf("%p\n",p);
// 	count = ft_printf("%p\n",p);
//     printf("\nLe VRAI total est : %d\nLe mien est %d\n", og_count, count);
//     return (0);
// }
