/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaldona <rmaldona@student42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:43:44 by rmaldona          #+#    #+#             */
/*   Updated: 2022/08/25 16:38:50 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_signals_bonus(unsigned char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(250);
		i++;
	}
}

void	convert_bonus(unsigned char str, int pid)
{
	unsigned char	*bits;
	size_t			j;

	j = 8;
	bits = malloc (9 * sizeof(char *));
	while (j)
	{
		bits[--j] = (str % 2) + 48;
		str = str / 2;
	}
	bits[8] = '\0';
	send_signals_bonus(bits, pid);
	free(bits);
}

void	finish(int n)
{
	(void)n;
	write(1, "message received!\n", 19);
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	signal(SIGUSR1, finish);
	if (argc != 3)
	{
		ft_printf("client: invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		convert_bonus(argv[2][i], pid);
		i++;
	}
	if (argv[2][i] == '\0')
		convert_bonus(0, pid);
	return (0);
}
