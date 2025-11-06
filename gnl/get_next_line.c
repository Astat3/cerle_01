/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:15:56 by agallot           #+#    #+#             */
/*   Updated: 2025/11/06 03:04:43 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>

char *get_next_line(int fd)
{
	static char *buffer;
	char *temp1;
	char *temp2;
	int	bytes;

	bytes = 0;
	buffer = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if(!buffer)
		return (NULL);
	temp1 = NULL;
	temp2 = NULL;
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes)
	{
		/*CHECK SI BUFFER = LIGNES COMPLETES ET/OU \N DEDANS
		SI OUI == COUPER ET RENVOYER EN INCLUANT LE N
		*/
		temp1 = check_buffer_fill(buffer);//fill en incluant le \n
		temp2 = temp1;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (temp1);
}
int main(void)
{
	int fd = open("rien.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
