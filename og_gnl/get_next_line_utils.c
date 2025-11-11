/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:04:55 by agallot           #+#    #+#             */
/*   Updated: 2025/11/11 14:12:21 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean(t_list **list, t_list *new_node, char *buffer)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (new_node->str_buf[0])
	{
		(*list) = new_node;
	}
	else
	{
		free(buffer);
		free(new_node);
	}
}

void	replace_node(t_list **list)
{
	t_list	*last_node;
	t_list	*new_node;
	char	*buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	new_node = malloc(sizeof(t_list));
	if (!buffer || !new_node || !*list)
		return ;
	last_node = get_last(*list);
	while (last_node->str_buf[i] != '\n' && last_node->str_buf[i] != '\0')
		if (last_node->str_buf[i] == '\n')
			i++;
	while (last_node->str_buf[i])
		buffer[j++] = last_node->str_buf[i++];
	buffer[j] = '\0';
	new_node->str_buf = buffer;
	new_node->next = NULL;
	clean(list, new_node, buffer);
}

void	copy_str(t_list *list, char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!list)
		return ;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				dest[j++] = '\n';
				dest[j] = '\0';
				return ;
			}
			dest[j++] = list->str_buf[i++];
		}
		list = list->next;
	}
	dest[j] = '\0';
}

int	to_newline(t_list *list)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

char	*get_line(t_list *list)
{
	char	*line;
	int		size;

	size = to_newline(list);
	if (list == NULL)
		return (NULL);
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	copy_str(list, line);
	return (line);
}
