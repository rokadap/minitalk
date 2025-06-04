/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:59:45 by rokada            #+#    #+#             */
/*   Updated: 2025/06/03 22:28:31 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, len1 + 1);
	ft_strlcat(new_str, s2, len1 + len2 + 1);
	return (new_str);
}

/* 
int	main(void)
{
	char	*result1;
	char	*result2;
	char	*result3;

	result1 = ft_strjoin("Hello, ", "world!");
	if (result1)
	{
		printf("%s\n", result1); // Expected output: Hello, world!
		free(result1);
	}
	result2 = ft_strjoin("42", "Tokyo");
	if (result2)
	{
		printf("%s\n", result2); // Expected output: 42Tokyo
		free(result2);
	}
	result3 = ft_strjoin("", "Empty");
	if (result3)
	{
		printf("%s\n", result3); // Expected output: Empty
		free(result3);
	}
	return (0);
} */