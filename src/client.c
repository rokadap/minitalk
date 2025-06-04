/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:05:11 by rokada            #+#    #+#             */
/*   Updated: 2025/06/04 19:19:39 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_signal(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_handler("kill error", "SIGUSR1");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_handler("kill error", "SIGUSR2");
		}
		usleep(WAIT_TIME);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		error_handler("Invalid arguments", "Usage: ./client <PID> <message>");
	if (!bool_atoi(argv[1], &pid))
		error_handler("Invalid PID", "PID must be a positive integer");
	if (pid <= 0 || pid > INT_MAX)
		error_handler("Invalid PID", "PID must be a positive integer");
	i = 0;
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	send_signal(pid, '\n');
	return (0);
}
