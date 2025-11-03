/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:32:59 by adamgallot        #+#    #+#             */
/*   Updated: 2025/10/15 18:59:39 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

typedef struct s_list
{
	void			*content; 
	struct s_list 	*next;
}				t_list;

void	del(void *ptr)
{
	free(ptr);
}

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *actual;
	t_list *tmp;
	
	if(!lst || !del)
		return;
	if(*lst == NULL)
		return ;
	actual = *lst; 
	while (actual)
	{
		tmp = actual->next;
		del(actual->content);
		free(actual);
		actual = tmp;
	}
	*lst = NULL;
}