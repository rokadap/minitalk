/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:22:00 by rokada            #+#    #+#             */
/*   Updated: 2025/06/03 22:23:52 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line_bonus.h"

void	*ft_free(void *p)
{
	free(p);
	return (NULL);
}

char	*ft_strchr(const char *string, int key)
{
	char	*str;

	str = (char *)string;
	while (*str != key && *str != '\0')
		str++;
	if (*str == key)
		return (str);
	else
		return (NULL);
}

size_t	ft_strlen(const char *string)
{
	int	count;

	count = 0;
	while (string[count])
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		allsize;
	int		i;
	int		j;

	allsize = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (allsize + 1));
	if (!result || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[allsize] = '\0';
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;

	result = malloc(count * size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}
