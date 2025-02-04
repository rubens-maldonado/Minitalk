/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaldona <rmaldona@student42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:31:12 by rmaldona          #+#    #+#             */
/*   Updated: 2022/08/23 23:38:52 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr(int signum)
{
	static int	bits = 0;
	static char	chr = 0;

	if (bits < 8)
	{
		if (signum == SIGUSR1)
		{
			chr += (1 << (7 - bits));
		}
		bits++;
	}
	if (bits == 8)
	{
		write(1, &chr, 1);
		chr = 0;
		bits = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	while (1)
		pause();
	return (0);
}
