/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaldona <rmaldona@student42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:43:44 by rmaldona          #+#    #+#             */
/*   Updated: 2022/08/25 16:36:53 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(unsigned char *str, int pid)
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

void	convert(unsigned char str, int pid)
{
	unsigned char	*bits;
	size_t			j;

	j = 8;
	bits = malloc(9 * sizeof(char *));
	while (j)
	{
		bits[--j] = (str % 2) + 48;
		str = str / 2;
	}
	bits[8] = '\0';
	send_signals(bits, pid);
	free(bits);
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("client: invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		convert(argv[2][i], pid);
		i++;
	}
	return (0);
}
