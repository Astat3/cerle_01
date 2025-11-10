/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:04:07 by agallot           #+#    #+#             */
/*   Updated: 2025/11/10 21:54:35 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

void    clean(t_list **list, t_list *new_node, char *buffer)
{
	t_list *tmp;

	 //pourquoi tmp sans malloc ?
	while (*list)
	{
		tmp = (*list)->next; //pourauoi parenthese
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
	// ici plus rien dans la liste
	*list = NULL;
	if (new_node->str_buf[0])
	{
		(*list)= new_node;   
	}
	else
	{
		free(buffer);
		free(new_node);
	}
}

void    replace_node(t_list **list) // met en first node tout apres le \n donc faut free
{
	t_list *last_node;
	t_list *new_node;
	char *buffer;
	int i;
	int j;

	i = 0;
	j = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	new_node = malloc(sizeof(t_list));
	if (!buffer || !new_node || !*list)
		return;
	last_node = get_last(*list);
	while (last_node->str_buf[i] != '\n' && last_node->str_buf[i] != '\0')// couille peut etre ici
		i++;
	i++;
	while (last_node->str_buf[i])
		buffer[j++] = last_node->str_buf[i++];
	buffer[j] = '\0';
	new_node->str_buf = buffer;
	new_node->next = NULL;
	clean(list,new_node, buffer);
}

void    copy_str(t_list *list, char *dest)
{
	int i;
	int j;
	 
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
				return; 
			 }  
			 dest[j++] = list->str_buf[i++];      
		}
		list = list->next;
	}
}
int to_newline(t_list *list)
{
	int i = 0;
	int len = 0;
	if (list == NULL)
		return 0;
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

char *get_line(t_list *list)
{
	char *line;
	int size; 
	
	size = to_newline(list);
	if (list == NULL)
		return (NULL);
	line = malloc(sizeof(char) * (size  + 1));
	if (!line)
		return NULL;
	copy_str(list, line);
	return (line);
	
}

int is_new_line(t_list *list)
{
	int i;
	i = 0;
	if (!list)
		return 0;
	while (list)//pour eviter les leaks ?
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
				return 1;
			i++;
		}
		list = list->next;
	}
	
	return 0;
	
}
t_list *get_last(t_list *list)
{
	if (!list)
		return NULL;
	while (list->next)
	{
	 list = list->next;   
	}
	return (list);
	
}

void appen_list(t_list **list, char *buf)
{
	t_list *new_node;
	t_list *last_node;

	new_node = malloc(sizeof(t_list));
	last_node = get_last(*list);
	if (!new_node || !new_node)  
		return ;
	new_node->str_buf= buf;
	new_node->next = NULL;
	if (*list == NULL)
	{
		*list = new_node;
	}
	else
	{
		last_node->next = new_node;
	}
	}


void    new_list(t_list **list, int fd)
{
	char *buf;
	int bytes;

	while (!is_new_line(*list))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0)
		{
			free(buf);
			return;			
		}
		buf[bytes] = '\0';
		appen_list(list, buf);
	}
}

char *get_next_line(int fd)
{
	static t_list *list;
	char    *next_line; 

	next_line = NULL;
	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	new_list(&list, fd); //creer la liste  et/ou append un nv balayage du buffer
	if (list == NULL)
	{
		return NULL;		
	}
	next_line = get_line(list);
	replace_node(&list);
	return (next_line);
}

// int main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *res = get_next_line(fd);
// 	printf("%s",res);
// 	if (fd == -1)
// 	{
// 		printf("Error\n");
// 		EXIT_FAILURE;
// 	}
// 	while (res)
// 	{
// 		printf("%s", res);
// 		res = get_next_line(fd);
// 		if (res == NULL)
// 		{
// 			printf("%s",res);
// 			break;
// 		}
// 	}
	
// }