/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:58:24 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/03 16:43:39 by agallot          ###   ########.fr       */
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*temp;

	if (!lst || !f || del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		if (f)
			temp = ft_lstnew(f(lst->content));
		else
			temp = ft_lstnew(lst->content);
		if (!temp)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, temp);
		lst = lst->next;
	}
	return (res);
}
