/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:34:39 by rokada            #+#    #+#             */
/*   Updated: 2025/06/03 22:16:03 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	ft_hex_len(unsigned int num)
{
	int		len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int num, char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + '0');
		else
		{
			if (format == 'x')
				ft_print_char(num - 10 + 'a');
			if (format == 'X')
				ft_print_char(num - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int num, char format)
{
	if (num == 0)
		return (ft_print_char('0'));
	else
		ft_put_hex(num, format);
	return (ft_hex_len(num));
}
