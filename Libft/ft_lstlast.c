/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:26:18 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/03 16:42:30 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

//last element has the next =null;
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
