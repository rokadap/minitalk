/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:05:04 by rokada            #+#    #+#             */
/*   Updated: 2025/06/03 22:53:53 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void signal_handler(int signal,siginfo_t *info,void *context)
{
    static int  bit;
    static char c;

    if (signal == SIGUSR1)
        c |= (1 << bit);
    bit++;
    if (bit == 8)
    {
        write(1, &c, 1);
        bit = 0;
        c = 0;
        if (info->si_pid > 0)
            kill(info->si_pid, signal);
    }
    (void)context;
}
int main(int  argc, char **argv)
{
    struct sigaction sa;

    (void)argv;
    if (argc != 1)
        error_handler("Invalid arguments", "Usage: ./server_bonus");
    ft_printf("Server PID: %d\n", getpid());
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handler;
    sigemptyset(&sa.sa_mask);
    if(sigaddset(&sa.sa_mask, SIGUSR1) == -1 ||
       sigaddset(&sa.sa_mask, SIGUSR2) == -1)
        error_handler("sigaddset error", NULL);
    if (sigaction(SIGUSR1, &sa, NULL) == -1 ||
        sigaction(SIGUSR2, &sa, NULL) == -1)
        error_handler("sigaction error", NULL);
    while (1)
    {
        pause();
        usleep(WAIT_TIME);
    }
    return (0);
}