/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:58:43 by adamgallot        #+#    #+#             */
/*   Updated: 2025/10/14 17:58:52 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list
{
	void			*content; 
	struct s_list 	*next;
}				t_list; 

t_list *ft_lstnew(void *content)
{
	t_list	*node; 

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);

	node->content = content; 
	node->next = NULL;

	return (node);

}
