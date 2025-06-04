/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:17:06 by rokada            #+#    #+#             */
/*   Updated: 2025/06/03 22:28:31 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		src_len;
	const char	*s;
	char		*d;

	src_len = 0;
	s = src;
	while (*s++)
	{
		src_len++;
	}
	if (dstsize == 0)
	{
		return (src_len);
	}
	d = dst;
	while (*src && --dstsize)
	{
		*d++ = *src++;
	}
	*d = '\0';
	return (src_len);
}

/*
int main() {
	char src[] = "Hello, World!";
	char dst[20];

	size_t len = ft_strlcpy(dst, src, sizeof(dst));

	printf("Copied string: %s\n", dst);
	printf("Length of src: %zu\n", len);

	return 0;
}
 */