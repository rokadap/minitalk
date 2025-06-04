/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:16:11 by rokada            #+#    #+#             */
/*   Updated: 2025/06/01 18:31:59 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	*ft_itoa(int n);
int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_pointer(unsigned long long ptr);
int		ft_print_integer(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, char format);

#endif