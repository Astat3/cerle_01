/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:15:56 by agallot           #+#    #+#             */
/*   Updated: 2025/11/06 05:21:00 by adamgallot       ###   ########.fr       */
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
int main(void)
{
	int fd = open("rien.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
