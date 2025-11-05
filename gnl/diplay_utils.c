/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diplay_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:19:06 by agallot           #+#    #+#             */
/*   Updated: 2025/11/05 20:43:01 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 45

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

int main(void)
{    
    char hello_world[100];
    char on_screen[5];

    
    while (
        fd = open(argv[i], O_RDONLY);
        if (fd < 0)
            continue;
        bytes_read = read(fd, buffer, BUFFSIZE);
        while(bytes_read)
        {
            ft_pustr(buffer);
            bytes_read = read(fd, buffer, BUFFSIZE);
            
        }
            
        
    
    read(0, on_screen, 5);
    read(0, hello_world, 100);
    write(1, on_screen, 5);
    return 0;
}