/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:15:56 by agallot           #+#    #+#             */
/*   Updated: 2025/11/10 15:56:29 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

/*
1 -> mettre un array de taille BUFFER_SIZE dans un node
2-> regarder si \n
3-> Si non
	res = NULL;
	swap = NULL;
	res = malloc(sizeof(char) * (is_newline(*tmp) + 1));
	if (! res)
		return (NULL);
	ft_memcpy(res, *tmp,is_newline(*tmp));
		// on copie en incluant \n | il faut copier le reste dans swap pr free tmp et remplacer temp par swap
	swap = malloc(sizeof(char) * (ft_strlen(* tmp) - ft_strlen(res)));,
		on continue
4-> si oui on coupe en incluant le \n
*/

int	is_newline(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_check_is_empty(char *tmp, char *buff)
{
	char	*hold_temp;
	int		size;

	size = 0;
	hold_temp = NULL;
	if (tmp)
	{
		hold_temp = ft_strdup(tmp);
		free(tmp);
		size = ft_strlen(buff) + ft_strlen(hold_temp);
		tmp = malloc(sizeof(char) * (size + 1));
		if (!tmp)
			return (NULL);
		ft_memcpy(tmp, hold_temp, ft_strlen(hold_temp) + 1);
		tmp[ft_strlen(hold_temp)] = '\0';
		ft_memcpy(ft_strchr(tmp, '\0'), buff, ft_strlen(buff));
		tmp[size] = '\0';
		free(hold_temp);
	}
	else if (!tmp)
		tmp = ft_strdup(buff);
	return (tmp);
}

void	aaaaaaaa(char **tmp)
{
	char	*swap;

	// printf("voila le swap %s fin", swap);
	swap = ft_strdup(ft_strchr(*tmp, '\n') + 1);
	free(*tmp);
	*tmp = swap;
}

char	*ft_final_cut(char **tmp, char **buff, int bytes)
{
	char	*res;
	char	*swap;

	swap = NULL;
	res = NULL;
	if (*tmp && **tmp && bytes == 0) // en cas de fin de fichier
	{
		swap = ft_strdup(*tmp);
		free(*tmp);
		*tmp = NULL;
		free(*buff);
		*buff = NULL;
		return (swap);
	}
	if (ft_strchr(*tmp, '\n') != NULL)
	{
		res = ft_substr(*tmp, 0, (ft_strlen(*tmp) - ft_strlen(ft_strchr(*tmp,
							'\n'))) + 1);
		aaaaaaaa(tmp);
		return (res);
	}
	free(res);	
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*buff;

	ssize_t bytes; // valeur de retour de read
	buff = malloc(sizeof(char) *(BUFFER_SIZE));
	bytes = read(fd, buff, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes)
	{
		if (ft_strchr(tmp, '\n')) // il a trouvé le char donc on renvoi line
			return (ft_final_cut(&tmp, &buff, bytes));
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		tmp = ft_check_is_empty(tmp, buff);
		free(buff);
		buff = NULL;
	}
	return (ft_final_cut(&tmp, &buff, bytes));
}
int	main(void)
{
	int		fd;
	char	*res;

	fd = 0;
	fd = open("note.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR\n");
		return (EXIT_FAILURE);
	}
	res = get_next_line(fd);
	while (res)
	{
		printf("%s", res);
		res = get_next_line(fd);
	}
	if (res == NULL)
	{
		printf("%s", res);
	}
	free(res);
}
