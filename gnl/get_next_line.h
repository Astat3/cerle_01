/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:16:22 by agallot           #+#    #+#             */
/*   Updated: 2025/11/06 03:00:28 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_H
# define GET_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#define BUFFER_SIZE 5

char *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char *check_buffer_fill(char *buffer);

#endif