/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:37:27 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/04 19:05:54 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_list	*ft_lst_last(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		return ;
	last_node = ft_lst_last(*lst);
	last_node->next = new;
	new->next = NULL;
}
