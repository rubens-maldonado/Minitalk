/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaldona <rmaldona@student42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:31:12 by rmaldona          #+#    #+#             */
/*   Updated: 2022/08/25 16:46:55 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler_sigusr_bonus(int signum, siginfo_t *info, void *null)
{
	static int	bits = 0;
	static char	chr = 0;

	(void)null;
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
		if (chr == 0)
			kill(info->si_pid, SIGUSR1);
		chr = 0;
		bits = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = handler_sigusr_bonus;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}
