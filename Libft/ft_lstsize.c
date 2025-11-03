/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:13:50 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/03 16:45:08 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int	ft_lstsize(t_list *lst)
{
	int	count;

	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
