/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:52:27 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/09 18:23:46 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int format_sel(char format, va_list *list)
{
	int count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(*list, int));
	else if(format == 's')
		count += print_string(va_arg(*list, char *));
	else if(format == 'i' || format == 'd')
		count += ft_print_nbr((long)va_arg(*list, int), "0123456789");
	else if(format == 'x')
		count += print_nbr_base((unsigned)(va_arg(*list,long int)), "0123456789abcdef");
	else if(format == 'X')
		count += print_nbr_base((unsigned)(va_arg(*list,long int)), "0123456789ABCDEF");
	else if(format == 'u')
		count += ft_print_nbr((unsigned)(va_arg(*list, long int)), "0123456789");
	else if(format == 'p')
    {
            unsigned long ptr_format = (unsigned long)(va_arg(*list, void *));
			count += print_string("0x");
			count += print_nbr_base(ptr_format,"0123456789abcdef");  
    }
	else
    {
     	count += write(1, &format, 1);   
    }
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

// int main(void)
// {
// 	int count = 0; 
// 	int og_count = 0;
    
// 	count = ft_printf("%p %p\n", LONG_MIN, LONG_MAX); // doit faire 38
// 	og_count = printf("%lx %lx\n", LONG_MIN, LONG_MAX);
// 	printf("count moi: %d\ncount og: %d\n", count, og_count);
// 	return 0;
// }
