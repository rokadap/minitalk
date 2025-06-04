/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:52:35 by rokada            #+#    #+#             */
/*   Updated: 2024/06/25 19:04:08 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)buf;
	while (n--)
	{
		*p = (unsigned char)ch;
		p++;
	}
	return (buf);
}
/*
int main()
{
	char buffer[10];
	ft_memset(buffer, 'A', 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%c", buffer[i]);
	}
	return (0);
} */