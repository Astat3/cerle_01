/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:50:57 by adamgallot        #+#    #+#             */
/*   Updated: 2025/10/15 18:59:45 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

typedef struct s_list
{
	void			*content; 
	struct s_list 	*next;
}				t_list;

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if(!lst || !f)
		return ; 
	while (lst)
	{
		f(lst->content);
		lst = lst->next; 
	}
}