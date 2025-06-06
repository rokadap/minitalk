/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:57:46 by rokada            #+#    #+#             */
/*   Updated: 2025/06/06 16:39:29 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../all_libft/include/libft.h"
# include <signal.h>
# include "ft_printf.h"

# ifdef __linux__
#  define WAIT_TIME 1100
# endif

# ifdef __APPLE__
#  define WAIT_TIME 50
# endif

#endif