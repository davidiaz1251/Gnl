/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:17:53 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/08 10:18:04 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_new;
	char	*init;

	if (!s1 && !s2)
		return (NULL);
	str_new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	init = str_new;
	if (!str_new)
		return (NULL);
	while (*s1)
		*str_new++ = *s1++;
	while (*s2)
		*str_new++ = *s2++;
	*str_new = '\0';
	return (init);
}

char	*ft_strchr(const char *s, int c)
{
	char	character;
	int		slen;
	int		i;

	slen = ft_strlen(s);
	character = (char)c;
	i = 0;
	while (i <= slen)
	{
		if (s[i] == character)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	if (n != 0)
	{
		while (n--)
		{
			*ptr++ = '\0';
		}
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	memory = (void *)malloc(count * size);
	if (!memory)
		return (NULL);
	else
	{
		if (!size)
			return ((void *)memory);
		else
		{
			ft_bzero (memory, (count * size));
			return ((void *)memory);
		}
	}
}
