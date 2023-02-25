/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:04 by tjukmong          #+#    #+#             */
/*   Updated: 2023/02/25 17:47:49 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>

# include <unistd.h>
# include <sys/signal.h>

# include "../lib/libft/libft.h"

typedef struct t_global
{
	pid_t	pid;
	pid_t	client;

	int		read_enable;
	char	buffer;
	int		bit;
}				t_global;

// Server utils
void	begin_server(t_global *g);
void	error_out(t_global *g, char *msg);
void	send_char(t_global *g, unsigned char c);

#endif