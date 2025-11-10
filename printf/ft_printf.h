/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:08:06 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/10 14:15:29 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRINTFT
# define PRINTFT

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		format_sel(char format, va_list *list);
void	ft_putstr(char *s);
void	ft_putchar(char c);
int		print_char(int c);
int		print_string(char *s);
int		count_num(long long unsigned int nbr, char *base);
int		print_nbr_base(unsigned long long int nbr, char *base);
int		ft_print_nbr(long int nbr, char *base);

#endif
