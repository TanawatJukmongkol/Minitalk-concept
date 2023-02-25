/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:18:37 by tjukmong          #+#    #+#             */
/*   Updated: 2023/02/25 18:07:00 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	begin_server(t_global *g)
{
	char	*pid_str;

	g->pid = getpid();
	if (!g->pid)
		error_out(g, "FATAL: Failed to start server!");
	pid_str = ft_itoa(g->pid);
	ft_putstr_fd("Info: Server started on port: ", 1);
	ft_putstr_fd(pid_str, 1);
	ft_putchar_fd('\n', 1);
	free(pid_str);
}

void	error_out(t_global *g, char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	send_char(t_global *g, unsigned char c)
{
	int				indx;
	unsigned int	byte;

	indx = 8;
	byte = c;
	// Send packet signal notify.
	kill(g->client, SIGUSR1);
	kill(g->client, SIGUSR2);
	// Send byte.
	while (indx--)
	{
		if (byte & 1)
			kill(g->client, SIGUSR1);
		else
			kill(g->client, SIGUSR2);
		byte >>= 1;
	}
}
