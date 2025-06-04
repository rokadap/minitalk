/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:04:56 by rokada            #+#    #+#             */
/*   Updated: 2025/06/03 22:55:51 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/minitalk.h"
#include "ft_printf.h"

void signal_handler(int signal)
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
    }
}

int main(int argc, char **argv)
{
    struct sigaction sa;

    (void)argv;
    if (argc != 1)
        error_handler("Invalid arguments", "Usage: ./server");
    ft_printf("Server PID: %d\n", getpid());
    sa.sa_flags = 0;
    sa.sa_handler = signal_handler;
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
