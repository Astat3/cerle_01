/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:03:07 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/03 16:41:15 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void	del(void *ptr)
{
	free(ptr);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
