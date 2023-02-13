/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:31:23 by ahaidour          #+#    #+#             */
/*   Updated: 2023/01/09 02:04:29 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_get(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_get(const char *s, int c)
{
	int	i;

	i = 0;
	while (i <= ft_strlen_get(s))
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_get(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s2)
		return (0);
	if (!s1)
		return (ft_strdup_get(s2));
	join = (char *)malloc((ft_strlen_get(s1) + ft_strlen_get(s2)) + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i++] = s2[j++];
	}
	join[i] = '\0';
	free(s1);
	return (join);
}

char	*ft_strdup_get(const char *s)
{
	char	*p;
	int		i;
	int		len;

	len = ft_strlen_get(s);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (p != NULL)
	{
		i = 0;
		while (i < len)
		{
			p[i] = s[i];
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
