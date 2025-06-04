/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:24:45 by rokada            #+#    #+#             */
/*   Updated: 2024/06/09 19:06:50 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_cp;
	char	*src_cp;

	if (dst == src || n == 0)
		return (dst);
	dst_cp = (char *)dst;
	src_cp = (char *)src;
	i = 0;
	while (i < n)
	{
		dst_cp[i] = src_cp[i];
		i++;
	}
	return (dst);
}

/*
int main()
{
	char src[10] = "Hello";
	char dst[10];
	ft_memcpy(dst, src, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%c ", dst[i]);
	}
	return 0;
}
 */