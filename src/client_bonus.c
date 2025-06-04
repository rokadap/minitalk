/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:05:15 by rokada            #+#    #+#             */
/*   Updated: 2025/06/04 19:15:42 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"
#include <signal.h>

void	ack_handler(int signal)
{
	if (signal == SIGUSR1 || signal == SIGUSR2)
		write (1, "ACK!!SIGUSR!!\n", 14);
}

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
	struct sigaction	sa;
	int					pid;
	int					i;

	if (argc != 3)
		error_handler("Invalid arguments", "Usage: ./client <PID> <message>");
	if (!bool_atoi(argv[1], &pid))
		error_handler("Invalid PID", "PID must be a positive integer");
	if (pid <= 0 || pid > INT_MAX)
		error_handler("Invalid PID", "PID must be a positive integer");
	sa.sa_flags = 0;
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1 ||
		sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		error_handler("Signal error", NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 ||
		sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler("Signal error", NULL);
	i = 0;
	while (argv[2][i])
		send_signal(pid, argv[2][i++]);
	send_signal(pid, '\n');
	usleep(WAIT_TIME);
	return (0);
}
