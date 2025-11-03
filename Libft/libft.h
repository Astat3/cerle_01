/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 00:29:18 by adamgallot        #+#    #+#             */
/*   Updated: 2025/10/17 15:52:59 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT
#define LIBFT


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*classique*/
char		*ft_strdup(const char *s);
int			ft_atoi(const char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *big, const char *little);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);




/*add*/
char	*ft_itoa(int n);
void	ft_puthchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);

//bonus
typedef struct s_list
{
	void			*content; 
	struct s_list 	*next;
}				t_list;

int ft_lstsize(t_list *lst);
t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *));
t_list *ft_lstlast(t_list *lst);
void ft_lstiter(t_list *lst, void (*f)(void *));
void ft_lstdelone(t_list *lst, void (*del)(void*));
void ft_lstclear(t_list **lst, void (*del)(void*));
void ft_lstadd_front(t_list **lst, t_list *new);
static t_list *ft_lst_last(t_list *lst);
t_list *ft_lstnew(void *content);
void ft_lstadd_back(t_list **lst, t_list *new);

#endif