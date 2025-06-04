/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:16:59 by rokada            #+#    #+#             */
/*   Updated: 2025/06/03 22:28:31 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;
	char		ch;

	last = NULL;
	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			last = s;
		s++;
	}
	if (ch == '\0')
	{
		return ((char *)s);
	}
	return ((char *)last);
}

/*
int main()
{
	const char *str = "Hello, World!";
	char ch = 'o';
	char *result = ft_strrchr(str, ch);

	if (result)
	{
		printf("Character '%c' found at position: %ld\n", ch, result - str);
	}
	else
	{
		printf("Character '%c' not found\n", ch);
	}

	return (0);
}
 */