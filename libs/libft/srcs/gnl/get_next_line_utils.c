/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:15:27 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/13 18:26:36 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

int	ft_strlcpy_gnl(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	if (!src || !dst)
		return (0);
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

void	*calloc_gnl(size_t nmemb, size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = (char *)malloc(nmemb * size);
	if (!(ptr))
		return (NULL);
	while (i < (nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

int	strchr_gnl(const char *s, int c)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)s;
	if (!s)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			return (i);
		}		
		i++;
	}
	if (s[i] == '\0' && (unsigned char)c == '\0')
		return (i);
	return (0);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int r)
{
	size_t	i;
	char	*str;
	int		len;

	if (!s2)
		return (0);
	len = ft_strlen(s1);
	if (r == BUFFER_SIZE)
		str = (char *)ft_calloc(sizeof(char), len + ft_strlen(s2) + 1);
	else
		str = (char *)ft_calloc(sizeof(char), len + r + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	i = 0;
	while (s2[i])
	{
		str[len + i] = s2[i];
		i++;
	}
	if (str[0] == '\0')
		free (str);
	free (s1);
	return (str);
}
