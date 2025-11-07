/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:15:56 by agallot           #+#    #+#             */
/*   Updated: 2025/11/07 15:07:37 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

/*
1 -> mettre un array de taille BUFFER_SIZE dans un node
2-> regarder si \n 
3-> Si non, on continue 
4-> si oui on coupe en incluant le \n
*/

int	is_newline(char *s)
{
	int	i;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return i;
		i++;
	}
	return -1;
	
}
char	*get_next_line(int fd)
{
	static char *tmp; 
	char		*buff;
	char		*res;
	ssize_t		bytes; //valeur de retour de read

	res = NULL;
	buff = NULL;
	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes)
	{
		if (is_newline(tmp) != -1) // il a trouvé le char donc on renvoi line
			tmp = ft_substr((tmp), is_newline(tmp), ft_strlen(tmp) - is_newline(tmp));
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if(!buff)
			return (NULL);
		bytes = read(fd, buff, BUFFER_SIZE);
		tmp = ft_strdup(buff);
		free(buff);
	}
	return (res);
}
int main(void)
{
	int fd = 0;
	
	fd = open("note.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur");
		return 1;
	}
	char *res = get_next_line(fd);
	while (res)
	{
		printf("%s", get_next_line(fd));
		res = get_next_line(fd);        
	}
	return 0;
}
