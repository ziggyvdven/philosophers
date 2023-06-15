/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:15:28 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/24 18:32:41 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// #include "../includes/push_swap.h"

int	ft_strcount(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i + 1] == c || str[i + 1] == '\0')
			&& !(str[i] == c))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strmake(char const *s, unsigned int start, unsigned int end)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)ft_calloc(sizeof(char), (end - start + 1));
	if (!(str))
		return (NULL);
	while (start < end && s)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

void	ft_free(char **ar)
{
	size_t	i;

	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		ar[i] = NULL;
		i++;
	}
	free(ar);
}

char	**ft_makear(char const*s, char **ar, unsigned int count, char c)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	start = 0;
	i = 1;
	ar[0] = "666";
	while (i <= count)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		ar[i] = ft_strmake(s, start, end);
		if (!(ar[i]))
		{
			ft_free((char **)ar);
			return (NULL);
		}
		i++;
		start = end;
	}
	return (ar);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**ptr;
	unsigned int	count;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_strcount(s, c);
	ptr = (char **)ft_calloc(sizeof(char *), count + 2);
	if (!(ptr))
		return (NULL);
	ptr = ft_makear(s, ptr, count, c);
	if (!(ptr))
		return (NULL);
	return (ptr);
}

// int	main(void)
// {
// 	char	*str = "\0aaa\0bbb";
// 	char	**arr;
// 	char	sep = '\0';
// 	int		i;

// 	arr = ft_split(str, sep);
// 	if (arr == NULL)
// 	{
// 		printf("ft_split returned NULL\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (arr[i] != NULL)
// 	{
// 		printf("%s\n", arr[i]);
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return (0);
// }
