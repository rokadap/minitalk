/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:37:09 by rokada            #+#    #+#             */
/*   Updated: 2025/06/04 20:12:00 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

#include <stdlib.h>
#include <unistd.h>

void	error_handler(const char *msg, const char *details)
{
	if (msg)
		ft_putstr_fd((char *)msg, 2);
	if (details)
		ft_putstr_fd((char *)details, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}
