/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:05:04 by rokada            #+#    #+#             */
/*   Updated: 2025/06/05 21:15:21 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"
#include <stdlib.h>

static t_client	*get_client(pid_t pid, t_client **clients)
{
	t_client	*cur;
	t_client	*new;

	cur = *clients;
	while (cur)
	{
		if (cur->pid == pid)
			return (cur);
		cur = cur->next;
	}
	new = malloc(sizeof(t_client));
	if (!new)
		exit(1);
	new->pid = pid;
	new->bit = 0;
	new->c = 0;
	new->next = *clients;
	*clients = new;
	return (new);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static t_client	*clients;
	t_client		*client;

	client = get_client(info->si_pid, &clients);
	if (signal == SIGUSR1)
		client->c |= (1 << client->bit);
	client->bit++;
	if (client->bit == 8)
	{
		if (client->c == '\0')
		{
			write(1, "\n", 1);
			if (info->si_pid > 0)
				kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &client->c, 1);
		client->bit = 0;
		client->c = 0;
	}
	(void)context;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		error_handler("Invalid arguments", "Usage: ./server_bonus");
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1
		|| sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		error_handler("sigaddset error", NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler("sigaction error", NULL);
	while (1)
	{
		pause();
		usleep(WAIT_TIME);
	}
	return (0);
}
