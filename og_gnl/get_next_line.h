/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:03:41 by agallot           #+#    #+#             */
/*   Updated: 2025/11/10 21:27:58 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_H
# define GET_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
typedef struct s_list
{
	char         *str_buf;
	struct s_list *next;
}t_list;

void    clean(t_list **list, t_list *new_node, char *buffer);
void    replace_node(t_list **list);
void    copy_str(t_list *list, char *dest);
int to_newline(t_list *list);

char *get_line(t_list *list);
int is_new_line(t_list *list);
t_list *get_last(t_list *list);
void appen_list(t_list **list, char *buf);
void    new_list(t_list **list, int fd);
char *get_next_line(int fd);

#endif