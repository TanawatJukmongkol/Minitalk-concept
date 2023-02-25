/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:11 by tjukmong          #+#    #+#             */
/*   Updated: 2023/02/25 18:35:24 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_global	g_socket;

void	sig_callback(int signum)
{
	if (g_socket.read_enable == 2)
	{
		if (signum == SIGUSR1)
			g_socket.buffer |= 0x1 << g_socket.bit;
		g_socket.bit++;
		if (g_socket.bit == 8)
		{
			printf("%c", g_socket.buffer);
			g_socket.bit = 0;
			g_socket.read_enable = 0;
			g_socket.buffer >>= 7;
		}
	}
	else
		g_socket.read_enable++;
}

int	main(int argc, char **argv)
{
	// Server side
	begin_server(&g_socket);
	signal(SIGUSR1, &sig_callback);
	signal(SIGUSR2, &sig_callback);

	// Client side
	g_socket.client = g_socket.pid;
	for (int i = 0; i < 10000; i++)
		send_char(&g_socket, 'A');

	return (0);
}
